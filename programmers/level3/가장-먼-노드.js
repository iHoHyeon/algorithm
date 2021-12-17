// https://programmers.co.kr/learn/courses/30/lessons/49189

const solution = (n, edge) => {
  const edgeMap = new Map();
  const already = new Set([1]);
  let lastMax;
  const nowMax = new Set();
  let flag = 0;

  edge.forEach((v) => {
    edgeMap.set(v[0], edgeMap.get(v[0]) ? edgeMap.get(v[0]).add(v[1]) : new Set([v[1]]));
    edgeMap.set(v[1], edgeMap.get(v[1]) ? edgeMap.get(v[1]).add(v[0]) : new Set([v[0]]));
    v[0] === 1 && already.add(v[1]) && nowMax.add(v[1]);
    v[1] === 1 && already.add(v[0]) && nowMax.add(v[0]);
  });

  nowMax.size || nowMax.add(1);

  while (!flag) {
    lastMax = new Set(nowMax.keys());
    nowMax.clear();
    lastMax.forEach((now) => {
      const connecteds = edgeMap.get(now);
      if (connecteds) {
        connecteds.forEach((con) => {
          !already.has(con) && nowMax.add(con) && already.add(con) && flag++;
        });
      }
    });

    flag = flag ? 0 : -1;
  }

  return lastMax.size;
};

/*
  초기화작업을 통해서 각 노드가 연결된 노드를 edgeMap에 저장

  1번 노드부터 출발하여 bfs 방식으로 조회

  가장 최근 조회된 노드Set(lastMax)와 현재 조회중인 노드Set(nowMax)를 갱신하며
  nowMax가 조회되지 않는다면 가장 마지막 노드를 조회했다는 의미이므로 flag를 갱신해서
  가장 최근 조회 목록의 개수 (lastMax.size)를 return 한다.

  생각해보면 flag를 굳이 세우지 않고 while문의 조건으로 nowMax.size를 걸면 더 이상 멀리 떨어진 노드가
  조회되지 않을 때까지 while 루프를 돌 수 있을 것 같다.. (BFS의 queue를 nowMax로 생각)
*/
