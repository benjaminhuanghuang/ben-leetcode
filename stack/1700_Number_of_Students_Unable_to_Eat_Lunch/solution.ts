/*
1700. Number of Students Unable to Eat Lunch

https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
*/

/*
 certain type of sandwich could not be taken by any student in the queue
*/
function countStudents(students: number[], sandwiches: number[]): number {
  // Initialize a count array where
  // index 0 represents students who prefer sandwich type 0,
  // index 1 represents students who prefer sandwich type 1.
  const sandwichPreferenceCount = [0, 0];

  // Count the number of students who prefer each type of sandwich
  for (const studentPreference of students) {
    sandwichPreferenceCount[studentPreference]++;
  }

  for (const sandwichType of sandwiches) {
    // If there are no students left preferring the current sandwich type,
    // return the count of students preferring the other type
    if (sandwichPreferenceCount[sandwichType] === 0) {
      return sandwichPreferenceCount[sandwichType ^ 1]; // toggles  sandwichType between 0 and 1
    }
    // Otherwise, decrement the count of students who prefer the current sandwich type
    sandwichPreferenceCount[sandwichType]--;
  }

  // If all students can be served with their preferred sandwich type,
  // return 0 indicating no students are left unserved
  return 0;
}
