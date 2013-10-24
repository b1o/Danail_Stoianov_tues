require 'csv'

CSV.open("results1.csv", "w") do |csv|
	Dir.glob("*_1.rb") do |file|
		begin
			result = `ruby #{file} 20/09/13 30/09/13`
			result = result.gsub(/[\n\r]/,"")
			csv << [file, result, result == ARGV[0]]
		rescue
			result = "Exception for #{file}"
			csv << [file, result, false]
		end
	end
end

