require 'io/console'
require 'time'

def countdown seconds
	private
	@counter = 1
	print "Countdown.."
	while @counter <= seconds do
		print "#{@counter}.."
		sleep 1
		@counter+=1
	end
	print "Go!\n"
end

y = 'y'
while y == 'y' do
	print "Times to press: "
	times = gets.chomp
	printf "Keys to press(2)"
	firstkey = gets.chomp
	secondkey = gets.chomp

	i = 0
	countdown 3
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
	if check == true
		t = sprintf("%0.02f", (time_end - time_start))
		print "You clicked #{times} clicks in #{t} seconds.\n"
	else
		print "You pressed a key different than the assigned in the begining. Terminating..\n"
	end

	printf("Do you want to try again? (Y/N): ")
	y = gets.chomp
	if y != 'y'
		y = 'n'
	end
end
