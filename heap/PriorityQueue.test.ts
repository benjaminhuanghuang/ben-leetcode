import { PriorityQueue } from "./PriorityQueue";

describe("PriorityQueue", () => {
  it("should return the max value", () => {
    const maxHeap = new PriorityQueue<number>((a, b) => a > b);
    maxHeap.add(1);
    maxHeap.add(2);
    maxHeap.add(3);

    expect(maxHeap.poll()).toEqual(3);
    expect(maxHeap.poll()).toEqual(2);
    expect(maxHeap.poll()).toEqual(1);
  });

  it("should return the max pair[1]", () => {
    const maxHeap = new PriorityQueue<number[]>(
      (a: number[], b: number[]) => a[1] > b[1]
    );
    maxHeap.add([0, 1]);
    maxHeap.add([1, 2]);
    maxHeap.add([1, 3]);

    expect(maxHeap.poll()).toEqual([1, 3]);
    expect(maxHeap.poll()).toEqual([1, 2]);
    expect(maxHeap.poll()).toEqual([0, 1]);
  });
});
