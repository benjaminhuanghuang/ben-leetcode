function calPoints(ops: string[]): number {
  const stack: number[] = [];

  for (const op of ops) {
    if (op === "+") {
      const last = stack[stack.length - 1];
      const secondLast = stack[stack.length - 2];
      stack.push(last + secondLast);
    } else if (op === "D") {
      stack.push(stack[stack.length - 1] * 2);
    } else if (op === "C") {
      stack.pop();
    } else {
      stack.push(Number(op));
    }
  }

  return stack.reduce((sum, score) => sum + score, 0);
}

export {};
