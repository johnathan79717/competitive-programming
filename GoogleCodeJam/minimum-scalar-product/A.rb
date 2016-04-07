#!/usr/bin/ruby

input = File.new(ARGV[0], 'r')
output = File.new(ARGV[0] + '.out', 'w')

T = input.gets.to_i
for t in 1..T
	n = input.gets.to_i
	v1 = input.gets.chomp.split.map{ |x| x.to_i }.sort
	v2 = input.gets.chomp.split.map{ |x| x.to_i }.sort{|a,b| -(a<=>b)}
	sum = 0
	for i in 0...n
		sum += v1[i] * v2[i]
	end
	output.puts "Case ##{t}: #{sum}"
end
