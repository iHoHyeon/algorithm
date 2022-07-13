function solution(s) {
  let cnt = 0;

  for (const w of s) {
    if ((w === 'p') | (w === 'P')) cnt++;
    else if ((w === 'y') | (w === 'Y')) cnt--;
  }

  return !cnt;
}
