import { PriorityQueue } from "../PriorityQueue";

type Order = [price: number, amount: number];

const MOD = 1_000_000_007;

function getNumberOfBacklogOrders(orders: number[][]): number {
  // buyBacklog: max-heap by price, highest buy price matches first
  const buyBacklog = new PriorityQueue<Order>((a, b) => a[0] > b[0]);
  // sellBacklog: min-heap by price, lowest sell price matches first
  const sellBacklog = new PriorityQueue<Order>((a, b) => a[0] < b[0]);

  for (const [price, amountRaw, orderType] of orders) {
    let amount = amountRaw;

    if (orderType === 0) {
      // buy order: match against cheapest sell orders in the backlog
      while (
        amount > 0 &&
        !sellBacklog.isEmpty() &&
        sellBacklog.peek()![0] <= price
      ) {
        const top = sellBacklog.peek()!;
        const matched = Math.min(amount, top[1]);
        amount -= matched;
        top[1] -= matched;
        if (top[1] === 0) sellBacklog.poll();
      }
      if (amount > 0) buyBacklog.add([price, amount]);
    } else {
      // sell order: match against highest buy orders in the backlog
      while (
        amount > 0 &&
        !buyBacklog.isEmpty() &&
        buyBacklog.peek()![0] >= price
      ) {
        const top = buyBacklog.peek()!;
        const matched = Math.min(amount, top[1]);
        amount -= matched;
        top[1] -= matched;
        if (top[1] === 0) buyBacklog.poll();
      }
      if (amount > 0) sellBacklog.add([price, amount]);
    }
  }

  let total = 0;
  let order: Order | undefined;
  while ((order = buyBacklog.poll())) total = (total + order[1]) % MOD;
  while ((order = sellBacklog.poll())) total = (total + order[1]) % MOD;

  return total;
}
