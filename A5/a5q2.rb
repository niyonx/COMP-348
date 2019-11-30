puts "Select one of the following options: 1. show the inventory, 2. import
a listing, 3. export to listing, 4. exit. "
input = gets.chomp.to_i
case input
when 1
    puts "you have selected inventory display option"
when 2
    puts "you have selected import a list option."
when 3
    puts "you have selected export to list option"
when 4
    puts "you have selected to exit the program"
else 
    puts "invalid input detected"
end
