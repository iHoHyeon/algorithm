// https://programmers.co.kr/learn/courses/30/lessons/42888

const enter = (name) => `${name}님이 들어왔습니다.`;
const leave = (name) => `${name}님이 나갔습니다.`;
const mapping = { Enter: enter, Leave: leave };

const solution = (record) => {
  const idMap = new Map();
  const splitedRecord = [];
  for (const msg of record) {
    const [com, id, name] = msg.split(' ');
    com !== 'Change' && splitedRecord.push([com, id]);
    com !== 'Leave' && idMap.set(id, name);
  }

  return splitedRecord.map(([com, id]) => mapping[com](idMap.get(id)));
};

/*
  모든 record를 1회 순회하면서 'Enter', 'Change'가 발생하면 id - name 맵핑을 갱신해주고
  'Enter', 'Leave'가 발생하면 result 출력을 위한 새로운 배열에 push 해준다.
  
  record의 마지막까지 순회할 때까지는 유저 nickname이 변경의 여지가 있기 때문에 
  마지막까지 순회를 마친 후 새로운 배열인 splitedRecord를 다시 돌면서 result를 생성해준다.

  
  풀이 후

  특별히 사용한 알고리즘은 없는 것 같다. 그냥 잘 구현하니까 풀린 문제
  후반 테스트에서 소요시간과 메모리 사용량이 급격히 늘어난다. 특별한 방법은 없는 것 같은데 다른 풀이도 참고해보자
*/
