/*
2424. Longest Uploaded Prefix

https://leetcode.com/problems/longest-uploaded-prefix/
*/

class LUPrefix {
  // A set to keep track of which videos have been uploaded.
  uploadedVideos: Set<number> = new Set();

  // Variable to track the longest sequence starting from video 1.
  longestSequence: number = 0;
  constructor(n: number) {}

  upload(video: number): void {
    // Insert the video number into the set of uploaded videos.
    this.uploadedVideos.add(video);

    // Check if the next consecutive video number is present;
    // if so, increment the counter for the longest sequence.
    while (this.uploadedVideos.has(this.longestSequence + 1)) {
      this.longestSequence++;
    }
  }

  longest(): number {
    // Return the current length of the longest continuous sequence from the start.
    return this.longestSequence;
  }
}
