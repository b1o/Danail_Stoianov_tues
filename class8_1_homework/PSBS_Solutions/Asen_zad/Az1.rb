require "csv"
all= Array.new()
bukva=ARGV[1].to_s


i=0

 CSV.foreach(ARGV[0],"r") do |row|
row[0].to_s

 
i=row[0].to_s.count(bukva)
if i>0
all<<[row[0],row[1],row[2]]

end




end
CSV.open("result.csv","w") do |csv| 
 all.sort.each do |l|
csv << [l[0],l[1],l[2]]
end
end
