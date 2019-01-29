class Node {
  edges: Map<string, Node> = new Map()
  prefix: string
  isWordEnd: boolean = false

  constructor(prefix = "") {
    this.prefix = prefix
  }

  // adds the char to the edge if not present, and returns the edge
  // or returns the edge if already present
  addChar = (char: string): Node => {
    if (this.edges.has(char)) {
      return this.edges.get(char)!
    }
    const node = new Node(this.prefix + char)
    this.edges.set(char, node)
    return node
  }

  addLeaf = (): Node => {
    const node = new Node(this.prefix)
    this.edges.set(this.prefix, node)
    node.isWordEnd = true
    return node
  }

  getEdge = (char: string): Node | undefined => {
    return this.edges.get(char)
  }
}

export default class Trie {
  _head = new Node()

  constructor(text: string) {
    this.addText(text)
  }

  /*
   Given a text, adds the text word by word to the trie
   for a text of size T, the size for Trie is O(T)
  */
   addText = (text: string) => {
    let currentNode = this._head
    const trimText = text.trim()
    for (let i = 0; i < trimText.length; i++) {
      const char = trimText.charAt(i)
      if (char === " ") {
        // this is the end of a word
        // the check in the if is to ensure that we dont take multiple spaces into account
        if (!currentNode.isWordEnd) {
          currentNode = currentNode.addLeaf()
        }
      } else {
        // if we had a end before, start again from head
        if (currentNode.isWordEnd) {
          currentNode = this._head
        }
        currentNode = currentNode.addChar(char)
      }
    }
    // the last word may not have a space
    if (!currentNode.isWordEnd) {
      currentNode.addLeaf()
    }
  }

  // walk the trie until we find the last matching char
  _walkTrieForBestMatch = (word: string): { node: Node, length: number } => {
    let currentNode: Node = this._head
    let i = 0;
    for (;i < word.length; i++) {
      const char = word.charAt(i)
      const node = currentNode.getEdge(char)
      if (node === undefined) break;
      else {
        currentNode = node
      }
    }
    // the head node has a empty char, so the length will be equal to index that we have walked so far
    return { node: currentNode, length: i }
  }

  // send empty word to accept partial matches
  _walkNodeToGetWords = (node: Node, patterns: Set<string>, word = "") => {
    if (node.isWordEnd) {
      // the if check is to avoid partial matches
      // for example, when we check for "partyy" we should not return "part"
      if (word.length <= node.prefix.length) {
        patterns.add(node.prefix)
      }
      return
    }
    for (const [key, value] of node.edges) {
      // the next constructed words' predecessor must have have the last predecssor + current key
      // like "lo" + "r" then onto "lor" then "e" and "m"
      this._walkNodeToGetWords(value, patterns, word) 
    }
  }

  hasWord = (word: string): boolean => {
    const { node, length } = this._walkTrieForBestMatch(word)
    const endNode = node.getEdge(word)
    const hasEndNode = endNode !== undefined && endNode.isWordEnd
    return (length === word.length && hasEndNode)
  }

  getSuggestions = (word: string, acceptPartialMatch = false): Set<string> => {
    const { node } = this._walkTrieForBestMatch(word)
    const patterns: Set<string> = new Set()
    this._walkNodeToGetWords(node, patterns, acceptPartialMatch ? "" : word)
    return patterns
  }

  getAllWords = (): Set<string> => {
    const words: Set<string> = new Set()
    this._walkNodeToGetWords(this._head, words)
    return words
  }
}