puts "Select one of the following options: \n 1. show the inventory \n 2. import a listing \n 3. export to listing \n 4. exit. "
input = gets.to_i
case input
when 1
    puts "you have selected inventory display option"
when 2
    puts "you have selected import a list option."
when 3
    puts "you have selected export to list option"
when 4
    puts "you have selected to exit the program"
    abort ("exiting the program...")
else 
    puts "invalid input detected"
end

def showInventory()
end

def importlisting()
end

def exportlisting()
end

def addtoInventory()
end

class Inventory
    @@total=0
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
    end 
    
    #accessor for each attribute
    def printItem
        puts @category
        puts @batteryLife
        puts @modelNum
        puts @color
        puts @manufacturer
        puts @status
        puts @yearBuilt
        puts @price
        puts @features
    end 

end