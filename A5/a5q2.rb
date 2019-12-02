class Inventory
    @@total=0
    @@array = Array.new

    def self.all_instances
        @@array
    end

    #constructor
    def initialize(category, batteryLife, modelNum, color, manufacturer, status, yearBuilt, price, features)
        @@total +=1
        @category = category
        @batteryLife = batteryLife
        @modelNum = modelNum
        @color = color
        @manufacturer = manufacturer
        @status = status
        @yearBuilt = yearBuilt 
        @price =price
        @features = features
        @@array << self
    end 
    
    #accessor for each attribute
    def printItem
        print @category,", "
        print @batteryLife,", "
        print @modelNum,", "
        print @color,", "
        print @manufacturer,", "
        print @status,", "
        print @yearBuilt,", "
        print @price,", "
        print @features
    end 
end

def showInventory()
    arrInventory = Inventory.all_instances
    arrInventory.each { |x| puts x.printItem }
end

def arrange(invStr)
    features = invStr.scan(/{(.*?)\}/)
    price = invStr.scan(/\d+\$/)
    puts features
end

def importlisting()
end

def exportlisting()
end

def addtoInventory()
    
end

puts "Select one of the following options: \n 1. show the inventory \n 2. import a listing \n 3. export to listing \n 4. exit. "
myInventory = Inventory.new("Laptop", "18hrs", "809F435RW", "silver", "Apple", "new", "2019", "1800$", "{Face ID, Retina display, Core-i5}")
myInventory = Inventory.new("Laptop", "18hrs", "809F435RW", "silver", "Apple", "new", "2019", "1800$", "{Face ID, Retina display, Core-i5}")
myInventory = Inventory.new("Laptop", "18hrs", "809F435RW", "silver", "Apple", "new", "2019", "1800$", "{Face ID, Retina display, Core-i5}")

input = gets.to_i
case input
when 1
    puts "you have selected inventory display option"
    showInventory()
when 2
    puts "you have selected add to inventory option, please enter the listing"
    invStr = gets.chomp
    arrange(invStr)
    
when 3
    puts "you have selected import a list option."
when 4
    puts "you have selected export to list option"
when 5
    puts "you have selected to exit the program"
    abort ("exiting the program...")
else 
    puts "invalid input detected"
end