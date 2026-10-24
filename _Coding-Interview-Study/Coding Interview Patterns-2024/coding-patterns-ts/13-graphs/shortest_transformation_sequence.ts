/*
Given two words. start and end, and a dictionary containing an array of words, return the
length of the shortest transformation sequence to transform start to end.

*/
function shortest_transformation_sequence(
  start: string,
  end: string,
  dictionary: string[]
): number {
  const dictionarySet = new Set(dictionary);

  if (!dictionarySet.has(start) || !dictionarySet.has(end)) {
    return 0;
  }

  if (start === end) {
    return 1;
  }

  const lowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
  const queue: string[] = [start];
  const visited = new Set<string>([start]);
  let dist = 0;

  // Use level-order traversal to find the shortest path from the
  // start word to the end word.
  while (queue.length > 0) {
    const levelSize = queue.length;

    for (let _ = 0; _ < levelSize; _++) {
      const currWord = queue.shift()!;

      // If we found the end word, we've reached it via the
      // shortest path.
      if (currWord === end) {
        return dist + 1;
      }

      // Generate all possible words that have a one-letter
      // difference to the current word.
      for (let i = 0; i < currWord.length; i++) {
        for (const c of lowerCaseAlphabet) {
          const nextWord = currWord.slice(0, i) + c + currWord.slice(i + 1);

          // If 'next_word' exists in the dictionary, it's a
          // neighbor of the current word. If unvisited, add it
          // to the queue to be processed in the next level.
          if (dictionarySet.has(nextWord) && !visited.has(nextWord)) {
            visited.add(nextWord);
            queue.push(nextWord);
          }
        }
      }
    }

    dist += 1;
  }

  // If there is no way to reach the end node, then no path exists.
  return 0;
}

/*

## Time Complexity

The time complexity of `shortest_transformation_sequence` is O(n x L^2), where:
- n denotes the number of words in the dictionary
- L denotes the length of a word

- Creating a hash set containing all the words in the dictionary takes O(n x L) time, 
   because hashing each of the n words takes O(L) time.
- Level-order traversal processes at most n words from the dictionary. 
At each of these words, we generate up to 26 x L transformations, and it takes O(L) time to 
check if a transformation exists in the visited and dictionary set hash sets, and to enqueue it. 

This means level-order traversal takes approximately O(n x 26 x L x L) = O(n x L^2) time.
Therefore, the overall time complexity is O(n x L) + O(n x L^2) = O(n x L^2).

## Space Complexity
The space complexity is O(n x L), taken up by the `dictionary_set` hash set, the `visited` hash set, and the queue.
*/
