import Trie from "../Trie"

describe('Trie', () => {
  it('check text presence', () => {
    const text = "Lorem ipsu ipsum"
    const trie = new Trie(text);
    expect(trie.hasWord("ipsu")).toBe(true);
    expect(trie.hasWord("Lorem")).toBe(true);
    expect(trie.hasWord("ipsum")).toBe(true);
    expect(trie.hasWord("Loremipsu")).toBe(false);
    expect(trie.hasWord("Lorem ")).toBe(false);
  });

  it('check all words', () => {
    const text = "santhosh prakash yoga"
    const trie = new Trie(text);

    const words = trie.getAllWords()
    expect(words.has("santhosh")).toBe(true);
    expect(words.has("prakash")).toBe(true);
    expect(words.has("yoga")).toBe(true);
    expect(words.has("flipkart")).toBe(false);
  });

  it('check suggestions', () => {
    const text = "santhosh prakash yoga santhoshv prakashn yogambo flipkart"
    const trie = new Trie(text);

    let suggestions = trie.getSuggestions("santh")
    expect(suggestions.has("santhosh")).toBe(true);
    expect(suggestions.has("santhoshv")).toBe(true);
    expect(suggestions.size).toBe(2);
    suggestions = trie.getSuggestions("praka")
    expect(suggestions.has("prakash")).toBe(true);
    expect(suggestions.has("prakashn")).toBe(true);
    expect(suggestions.size).toBe(2)
    suggestions = trie.getSuggestions("yoga")
    expect(suggestions.has("yogambo")).toBe(true)
    expect(suggestions.size).toBe(2)
    suggestions = trie.getSuggestions("yogam")
    expect(suggestions.has("yogambo")).toBe(true)
    expect(suggestions.size).toBe(1)
    suggestions = trie.getSuggestions("flipk")
    expect(suggestions.size).toBe(1)
    suggestions = trie.getSuggestions("flipkarty")
    expect(suggestions.size).toBe(0);
    suggestions = trie.getSuggestions("flipkarty", true)
    expect(suggestions.size).toBe(1);
  });
})