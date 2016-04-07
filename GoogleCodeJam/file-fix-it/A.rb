#!/usr/bin/ruby

input = File.new(ARGV[0], 'r')
output = File.new(ARGV[0]+'.out', 'w')

T = input.gets.to_i
for t in 1..T
	n, m = input.gets.chomp.split.map {|x| x.to_i}
	existed = Array.new(n)
	root = {}
	n.times do 
		line = input.gets.chomp
		line.slice!(0)
		path = line.split '/'
		dir = root
		path.each do |subdir|
			dir[subdir] = {} unless dir[subdir]
			dir = dir[subdir]
		end
	end
	count = 0
	m.times do 
		line = input.gets.chomp
		line.slice!(0)
		path = line.split '/'
		dir = root
		path.each do |subdir|
			unless dir[subdir]
				dir[subdir] = {}
				count += 1
			end
			dir = dir[subdir]
		end
	end
	output.puts "Case ##{t}: #{count}"
end
