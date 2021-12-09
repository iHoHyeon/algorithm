// https://programmers.co.kr/learn/courses/30/lessons/17676

const solution = (lines) => {
  let res = 0;
  const times = lines.map((line) => {
    const [dmy, hms, len] = line.split(' ');
    const endTime = new Date(dmy + ' ' + hms).getTime();
    return [endTime - Number(len.slice(0, -1)) * 1000 + 1, endTime];
  });

  for (const [start, end] of times) {
    let [res1, res2, res3, res4] = [0, 0, 0, 0];
    for (const [s, e] of times) {
      if ((start <= s && s < start + 1000) || (start < e && e <= start + 1000) || (s <= start && e >= start + 1000)) res1++;
      if ((start - 1000 < s && s <= start) || (start - 1000 < e && e <= start) || (s <= start - 1000 && e >= start)) res2++;
      if ((end - 1000 <= s && s < end) || (end - 1000 < e && e <= end) || (s <= end - 1000 && e >= end)) res3++;
      if ((end <= s && s < end + 1000) || (end < e && e <= end + 1000) || (s <= end && e >= end + 1000)) res4++;
      if (end + 1000 <= s) break;
    }

    res = Math.max(res1, res2, res3, res4, res);
  }
  return res;
};

/*
  풀이 시간: 대략 1시간

  초를 제외한 날짜 / 시간 / 분 등이 넘어가는 것이 어려워서 Date 객체의 getTime() 메서드를 사용

  입력으로 들어온 lines의 정보를 이용해서 데이터 로그 -> [시작시각, 끝시각] 으로 맵핑해주었다.

  동시에 처리되는 처리량이 변하는 경우는 각 구간의 시작 or 끝에서만 변하므로 양 끝에서 생길 수 있는 구간을 모두 확인했다.

  하나의 양 끝을 각각 시작 / 끝으로 하나의 1초 구간이 생기며 다시 모든 구간을 돌면서 포함되는 구간이 있는지 확인해준다.
  
  이중 for문으로 인해서 찝찝했지만 다른 방법들로는 해결이 어려워서 우선 구현했다.

  다른 사람들의 풀이가 너무 다양한데, 천천히 학습할 예정!
*/
