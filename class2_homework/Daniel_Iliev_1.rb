require "csv"
sum = 0
sum_decrease = 0
CSV.foreach("Bank.csv") do |row|
    if row[0] == "20/09/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "21/09/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "22/09/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "23/09/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "24/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "25/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "26/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "27/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "28/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end
CSV.foreach("Bank.csv") do |row|
    if row[0] == "29/10/2013"
    sum = sum + row[1].to_i
    sum_decrease = sum_decrease + row[2].to_i
    end
end

sum1 = sum;
sum = sum - sum_decrease
print sum1,"/",sum_decrease,"/",sum
