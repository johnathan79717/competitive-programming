#!/usr/bin/ruby

input = File.new(ARGV[0], 'r')
output = File.new(ARGV[0]+'.out', 'w')

T = input.gets.to_i
for t in 1..T
	n = input.gets.to_i
	output.puts "Case ##{t}: "
end
