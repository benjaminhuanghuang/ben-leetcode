# String Pattern problems

Use a map

```ts
const map = new Map<string, number>();
```

Don't use object

```ts
const wordPattern: { [key: string]: string } = {};
```

Becuse 'constructor' is the key for the contructor function in the object
