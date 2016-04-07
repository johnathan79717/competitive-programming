input = File.new(ARGV[0], "r")
output = File.new(ARGV[0]+'.out', "w")
N = input.gets.to_i
for i in 1..N
	output.puts "Case ##{i}: #{input.gets.chomp.split.reverse.join ' '}"
end
