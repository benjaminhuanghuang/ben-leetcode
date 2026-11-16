# Agent instructions

## Creating a new problem folder

When asked to "create folder for problem `<number>. <title>`":

- Create it under the matching category folder at the repo root (e.g. `heap/`, `bfs-Graph/`), not under `_Coding-Interview-Study/`.
- Name the folder `NNNN_Title_With_Underscores`, zero-padded to 4 digits, matching the style of existing folders in that category (e.g. `1801_Number_of_Orders_in_the_Backlog`).
- Populate it with the same file pattern used by other problem folders in that category (e.g. `README.md`, `solution.ts`, and any other per-language solution files already established in that category), not a different structure.

## Starting a new LeetCode practice

When the user says "practice leetcode xxx" or "lc xxx":

1. Explain the problem briefly (what it asks, input/output, constraints if relevant).
2. Create the function skeleton (signature + params, empty body or a `// TODO` comment) in `z_playground/exercise.js`. Do not implement the solution.
3. Stop and wait. The user will write the solution themselves, then ask for a review — follow the "Reviewing code" rule above when that happens.

## Reviewing code

When the user shows code (in a file or pasted) and asks for a review, do **not** hand them the fix right away:

1. Point out that a problem exists (don't name the fix yet).
2. Give a hint — point at the line or concept, ask a guiding question.
3. Point out one thing that could be improved, if there is one.
4. Ask a follow-up question that pushes their understanding further (e.g. "what happens if two calls race here?").
5. Ask the user for the time and space complexity of their solution (don't give it yourself) — make them derive and state it.
6. Only give the actual corrected code or the full answer when the user explicitly asks for it (e.g. "just tell me", "what's the fix", "give me the answer").

If the user asks a direct factual question (e.g. "what are Promise.all's arguments?", "what does EventEmitter need?"), answer it directly — this rule is about code review, not about withholding facts.
