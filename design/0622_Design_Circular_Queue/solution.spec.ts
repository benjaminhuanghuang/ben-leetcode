import { MyCircularQueue_Error as MyCircularQueue } from "./leetcode_622_design-circular-queue";

describe("MyCircularQueue", () => {
  it("should return the minimum path sum from top to bottom", () => {
    const myCircularQueue = new MyCircularQueue(3);
    expect(myCircularQueue.enQueue(1)).toBeTruthy(); // return True
    expect(myCircularQueue.enQueue(2)).toBeTruthy(); // return True
    expect(myCircularQueue.enQueue(3)).toBeTruthy(); // return True
    expect(myCircularQueue.enQueue(4)).toBeTruthy(); // return False
    expect(myCircularQueue.Rear()).toBe(3); // return 3
    expect(myCircularQueue.isFull()).toBeTruthy(); // return True
    expect(myCircularQueue.deQueue()).toBeTruthy(); // return True
    expect(myCircularQueue.enQueue(4)).toBeTruthy(); // return True
    expect(myCircularQueue.Rear()).toBe(4); // return 4
  });
});
