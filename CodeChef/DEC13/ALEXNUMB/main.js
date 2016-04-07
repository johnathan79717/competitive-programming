importPackage(java.io);
importPackage(java.lang);
var stdin = new BufferedReader(new InputStreamReader(System['in']));
var T = parseInt(stdin.readLine());
while(T--) {
  var n = parseInt(stdin.readLine());
  stdin.readLine();
  print(n * (n-1) / 2);
}
