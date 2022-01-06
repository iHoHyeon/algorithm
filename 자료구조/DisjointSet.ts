class DisjointSet {
  private parent: Array<number>;
  private level: Map<number, number>;
  private size: Map<number, number>;

  constructor(nums: number) {
    this.parent = new Array(nums);
    this.level = new Map();
    this.size = new Map();

    for (let node = 0; node < nums; node++) {
      this.parent[node] = node;
      this.level.set(node, 0);
      this.size.set(node, 1);
    }
  }

  find(x: number): number {
    if (x === this.parent[x]) return x;
    return (this.parent[x] = this.find(this.parent[x]));
  }

  union(x: number, y: number): boolean {
    const rootX = this.find(x);
    const rootY = this.find(y);

    if (rootX === rootY) return false;

    const levelX = this.level.get(rootX);
    const levelY = this.level.get(rootY);

    const sizeX = this.size.get(rootX);
    const sizeY = this.size.get(rootY);

    if (levelX > levelY) {
      this.parent[rootY] = rootX;
      this.size.set(rootX, sizeX + sizeY);
    } else if (levelX < levelY) {
      this.parent[rootX] = rootY;
      this.size.set(rootY, sizeX + sizeY);
    } else {
      this.parent[rootY] = rootX;
      this.level.set(rootX, levelX + 1);
      this.size.set(rootX, sizeX + sizeY);
    }

    return true;
  }

  getSetSize(x: number): number {
    const rootX = this.find(x);

    return this.size.get(rootX);
  }
}

const DS = new DisjointSet(5);

DS.union(1, 2);
DS.union(3, 2);
console.log(DS.getSetSize(1));
console.log(DS.getSetSize(4));

/*
  트리 구조를 가지는 Disjoint Set, 

  find(x) : x가 속한 set의 루트 노드를 반환한다.

  union(x, y) : x, y가 속한 set을 합친다. 서로 같은 집합이라면 false를 return

  getSetSize(x) : x가 속한 set의 원소 개수를 반환한다.

  https://www.acmicpc.net/problem/18116 이 문제를 풀고 트리구조로 구현해보았다.
*/
