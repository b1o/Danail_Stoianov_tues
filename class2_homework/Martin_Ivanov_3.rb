require "csv"
require "date"

information=Hash.new(0.0)


	CSV.foreach("bank.csv") do |row|
		information[Date.strptime(row[0], '%d/%m/%Y') ]+=row[1].to_f
	end

	max=information.max_by{ |date,income| income }
        puts max[0]
