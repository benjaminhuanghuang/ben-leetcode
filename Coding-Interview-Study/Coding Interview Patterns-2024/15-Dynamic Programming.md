# Dynamic Programming P309

problems can be broken down into subproblems
Recursion is often used to solve problems like these,
However, in the recursive process, it's possible to generate and solve the same subproblem multiple
times, which can be unnecessarily expensive.

DP is the antidote to this. It's a technique that stores solutions to each subproblem, so they can
be reused when they're needed again.

- Optimal substructure: the optimal solution to a problem can be constructed from the optimal
  solutions to its subproblems.

- Overlapping s1ubproblems: if the same subproblems are solved repeatedly during the problem-solving process.

- Recurrence relation: a formula that expresses the solution to the problem in terms of the
  solutions to its subproblems.

- Base cases: the simplest instances of the problem where the solution is already known, without
  needing to be decompo.sed into more subproblems.

If you spot keywords like 'minimum', 'maximum', 'longest', or 'shortest', in the problem description,
consider whether a DP approach might be appropriate
