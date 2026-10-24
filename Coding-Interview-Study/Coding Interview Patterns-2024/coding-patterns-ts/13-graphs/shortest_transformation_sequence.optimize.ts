function shortestTransformationSequenceOptimized(
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

  const startQueue: string[] = [start];
  const startVisited = new Set<string>([start]);
  const endQueue: string[] = [end];
  const endVisited = new Set<string>([end]);
  let levelStart = 0;
  let levelEnd = 0;

  // Perform a level-order traversal from the start word and another
  // from the end word.
  while (startQueue.length > 0 && endQueue.length > 0) {
    // Explore the next level of the traversal that starts from the
    // start word. If it meets the other traversal, the shortest
    // path between 'start' and 'end' has been found.
    levelStart += 1;
    if (exploreLevel(startQueue, startVisited, endVisited, dictionarySet)) {
      return levelStart + levelEnd + 1;
    }

    // Explore the next level of the traversal that starts from the
    // end word.
    levelEnd += 1;
    if (exploreLevel(endQueue, endVisited, startVisited, dictionarySet)) {
      return levelStart + levelEnd + 1;
    }
  }

  // If the traversals never met, then no path exists.
  return 0;
}

// This function explores the next level in the level-order traversal
// and checks if two searches meet.
function exploreLevel(
  queue: string[],
  visited: Set<string>,
  otherVisited: Set<string>,
  dictionarySet: Set<string>
): boolean {
  const lowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
  const levelSize = queue.length;

  for (let _ = 0; _ < levelSize; _++) {
    const currentWord = queue.shift()!;

    for (let i = 0; i < currentWord.length; i++) {
      for (const c of lowerCaseAlphabet) {
        const nextWord = currentWord.slice(0, i) + c + currentWord.slice(i + 1);

        // If 'next_word' has been visited during the other
        // traversal, it means both searches have met.
        if (otherVisited.has(nextWord)) {
          return true;
        }

        if (dictionarySet.has(nextWord) && !visited.has(nextWord)) {
          visited.add(nextWord);
          queue.push(nextWord);
        }
      }
    }
  }

  // If no word has been visited by the other traversal, the searches
  // have not met yet.
  return false;
}
/*
Time complexity: The time complexity of shortest_transformation_sequence_optimized is
O(n x L^2), since we're performing two level-order traversals. Note that this is more efficient in
practice since there are potentially fewer nodes to traverse when using bidirectional traversal.

Space complexity: The space complexity is O(n x L), taken up by the dictionary_set hash set,
both visited hash sets, and both queues.
*/
