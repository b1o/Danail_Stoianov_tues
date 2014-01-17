require 'io/console'
require 'time'

=begin
def bpm (clicks, seconds)
	clicks
end	
=end


y = 'y'
while y == 'y' do
	print "Times to press: "
	times = gets.chomp
	#if times.instance_of? Integer
		#print "haha"
	#end
	printf "Keys to press(2)"
	firstkey = gets.chomp
	secondkey = gets.chomp

	i = 0a
	if STDIN.getch != nil
		time_start = Time.new
		while i <= times.to_i - 1
			input = STDIN.getch
			if input == firstkey or input == secondkey
				i += 1
				check = true
			else
				check = false
				break
			end
		end
		time_end = Time.new
	end
	
	if check == true
		t = sprintf("%0.02f", (time_end - time_start))
		print "You clicked #{times} clicks in #{t} seconds.\n"
	else
		print "You pressed a key different than the assigned in the begining. Terminating..\n"
	end

	printf("Do you want to try again? (Y/N): ")
	y = gets.chomp
	y = y.downcase
	if y != 'y'
		y = 'n'
	end
end
