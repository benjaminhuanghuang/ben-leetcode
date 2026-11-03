/*
Time: O(n^2) — for each friend, we scan the chairs twice.
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

  // chairs[i] = null if empty, otherwise { friendId, leavingTime }
  const chairs = new Array(n).fill(null);

  for (const friend of friends) {
    const { arrival, leaving, id } = friend;

    // Step 1: Release chairs of friends who have already left
    for (let i = 0; i < n; i++) {
      if (chairs[i] !== null && chairs[i].leavingTime <= arrival) {
        chairs[i] = null;
      }
    }

    // Step 2: Find the smallest available chair
    for (let i = 0; i < n; i++) {
      if (chairs[i] === null) {
        chairs[i] = {
          friendId: id,
          leavingTime: leaving,
        };

        // Step 3: Return the chair assigned to targetFriend
        if (id === targetFriend) {
          return i;
        }

        break;
      }
    }
  }
};
