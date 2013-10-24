Dota_heroes_str = []
File.foreach(ARGV[0]) do |row|
 if row =~ /#{ARGV[1]}/
  Dota_heroes_str << row.split(",")[1]
 end
end
Dota = Dota_heroes_str.sort{|a,b| b <=> a}
File.open("dota2.csv", "w")  do |file|
 Dota.each do |element|
         file << element+"\r"
 end
end