# Disjoint-set / Union-find

Problems that can be solved with Union-Find can also be solved with DFS.
Find(X) find the root/cluster-id of X
Union(x, y): merge two clusters

Init: every node points to it self
Find(Id) = Id

## Tempalte

```js
class UnionFind {
    id: Map<number, number>;
    constructor() {
        this.id = new Map();
    }

    find(x) {
        let y = this.id.has(x) ? this.id.get(x) : x;
        if (y != x) {
            y = this.find(y);
            this.id.set(x, y);
        }
        return y;
    }

    union(x, y) {
        this.id.set(this.find(x), this.find(y));
    }
}

```

## reference

<https://www.youtube.com/watch?v=VJnUwsE4fWA> (HuaHua)

## Leetcode list

- 399. Evaluate Division <https://youtu.be/UwpvInpgFmo>
- 547. Friend Circles <https://youtu.be/HHiHno66j40>
- 737. Sentence Similarity II <https://www.youtube.com/watch>?
- 684. Redundant Connection <https://www.youtube.com/watch> v=4hJ721ce010
- 685. Redundant Connection II <https://youtu.be/lnmJT5b4NlM>
- 839. Similar String Groups
- 959. Regions Cut By Slashes <https://youtu.be/n3s9Q7GtfB4>

- 1061. Lexicographically Smallest Equivalent String
