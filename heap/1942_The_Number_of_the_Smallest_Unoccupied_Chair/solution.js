/*

I use two min heaps. One stores available chair numbers, ordered by chair ID. 
The other stores occupied chairs, ordered by leaving time. 
Before assigning a chair to each arriving friend, I release all chairs belonging 
to friends who have already left. Then I assign the smallest available chair. 
This gives us an O(n log n) solution.

Time: O(n log n) — Sorting: O(n log n), enqueue/dequeue: O(log n) for each friend.
Space: O(n) — to store the chairs and sorted friends.
*/
var smallestChair = function (times, targetFriend) {
  const n = times.length;

  // Sort friends by arrival time
  const friends = times
    .map(([arrival, leaving], id) => ({
      arrival,
      leaving,
      id,
    }))
    .sort((a, b) => a.arrival - b.arrival);

  // Min heap: available chair numbers
  const available = new MinPriorityQueue();

  // Min heap: occupied chairs, ordered by leaving time
  const occupied = new MinPriorityQueue({
    priority: (x) => x.leaving,
  });

  // Initially, all chairs are available
  for (let i = 0; i < n; i++) {
    available.enqueue(i);
  }

  for (const friend of friends) {
    const { arrival, leaving, id } = friend;

    // Release chairs of friends who have left
    while (!occupied.isEmpty() && occupied.front().element.leaving <= arrival) {
      const { chair } = occupied.dequeue().element;
      available.enqueue(chair);
    }

    // Assign the smallest available chair
    const chair = available.dequeue().element;

    // Return the target friend's chair
    if (id === targetFriend) {
      return chair;
    }

    // Mark the chair as occupied
    occupied.enqueue({ chair, leaving }, leaving);
  }
};
