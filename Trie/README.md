# Trie

A **Trie**, also called digital tree/ radix tree or prefix tree (as they can be searched by prefixes).

It is used for finding some or all places in a text where the query string occurs as a substring.

* For a given text of size T, the **space complexity** is **O(T)**
* For a substring/ prefix of size P which has to be searched in the text, the **search query complexity** is **O(P)**

## Useful for

* Suggestions for a complete word while typing
* Spell checkers
* File name searching
* Validate a word

## Setup

```bash
npm install
```

## Test

```bash
npm test
```

## Resources

* [YouTube - Basics of Tries - Gayle Laakmann McDowell](https://www.youtube.com/watch?v=zIjfhVPRZCg)

* [MIT - Advanced DS - Lecture 16 - see for running times and alternative implementations](https://courses.csail.mit.edu/6.851/spring12/lectures/L16.html?notes=2)