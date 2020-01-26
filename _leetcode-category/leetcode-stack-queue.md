# Stack, queue, dqueue, and priroity queue
- C++
queue and stack are higher level containers than deque, vector, or list. You can build a queue or stack out of the lower level containers.
```
stack<int, deque<int> > s;

queue<double, list<double> > q;

// In c++ priority_queue is max heap by default
priority_queue<string, deque<string>, greater<string>> pq;    // min heap

pq.push(x);    # push
y = pq.top();  # peek
pq.pop(q, x);  # pop 
```
 

- Java
```
Stack<TreeNode> stack = new Stack<>();

Queue<TreeNode> queue = new LinkedList<>();

Deque<String> deque = new LinkedList<>(); 
deque.add("Element 1 (Tail)"); // add to tail 
deque.addFirst("Element 2 (Head)"); 
deque.addLast("Element 3 (Tail)"); 
deque.push("Element 4 (Head)"); //add to head 
deque.offer("Element 5 (Tail)"); 
deque.offerFirst("Element 6 (Head)"); 
deque.offerLast("Element 7 (Tail)"); 
    
// In java priority_queue is min heap by default
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.offer(x);          # ppush
int min = pq.peek();  # peek
pq.poll(q, x);        # pop 

// priority_queue with comparator
PriorityQueue<int[]> pqPro = new PriorityQueue<>((a, b) -> (b[1] - a[1]));
```

- C#
```
```

- Python
Python's built-in list data structure comes bundled with methods to simulate both stack and queue operations.

```
stack = []

stack.append('1')  
stack.append('2')  
stack.append('3')  
stack.append('4')

last_item = stock.pop()  
```
```
queue = []

queue.append('1')  
queue.append('2')  
queue.append('3')  
queue.append('4')

// pop element at position
first_item = fruits.pop(0)  
```
Priority Queue in Pthon is min-heap
```
pq = [2, 4, 1, 3]
heapq.heapify(q)
heapq.heappush(q, x)    # ppush
y = q[0]                # peek
heapq.heappop(q, x)     # pop 
```
- JavaScript and TypeScript
push() method can append one or more elements to the end of an array.
pop() method pulls the last element off of the given array and returns it. 

unshift() like the push() method, only it works at the beginning of the array. 
shift() like the pop() method, only it works at the beginning of the array.

```
var stack=[];
stack.push("A);
stack.push("B");
stack.push("C"
alert(stack.pop());
alert(stack.pop());
alert(stack.pop());
```
```
var queue=new Array();
queue.push("A);
queue.push("B");
queue.push("C");

alert(queue.shift());
alert(queue.shift());
alert(queue.shift());
```

- Go
```
```








