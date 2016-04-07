n = parseInt(readline());
var s = [];
for(var i = 0; i < n; i++)
  s[i] = parseInt(readline());

s.sort(function(a, b) {return a - b;});
// print(s);

var lb = 0, ub = Math.floor(n/2) + 1;

function check(mid) {
  for(var i = 0; i < mid; i++)
    if(s[i] * 2 > s[n - mid + i])
      return false;
  return true;
}

while(ub - lb > 1) {
  var mid = Math.floor(lb + (ub - lb) / 2);
  // if(n === 77777)
  //   print(lb, ub);
  if(check(mid))
    lb = mid;
  else
    ub = mid;
}

print(n - lb);
