
#Function: Choose Flavor 
#Inputs: Season, Bottles, Cans 
#Outputs: None 
#Returns: Brewed Beer 
def chooseFlavor(season, packaging): 
    beerLabel = ""
    p = ""
    if season == 1: 
        s = "Welcome the Fresh Flavors of Spring!"
        f = "ROSE&STRAWBERRY"
        beerLabel = brewBeer(s, f)
    elif season == 2: 
        s = "Enjoy a Sip of Sunny Summer!"
        f = "ORANGE&LEMON"
        beerLabel = brewBeer(s, f)
    elif season == 3: 
        s = "Cozy Up With a Hint of Fall!"
        f = "APPLE&CINNAMON"
        beerLabel = brewBeer(s, f)
    else: 
        s = "Hit The Slopes Responsibly!"
        f = "PINE&MAPLE"
        beerLabel = brewBeer(s, f)
    if packaging == 1: 
        p = "355ML/12 US FL OZ BOTTLES"
    elif packaging == 2: 
        p = "355ML/12 US FL OZ CANS"
    else: 
        p = "355ML/12 US FL OZ BOTTLES&CANS"
    return(beerLabel + " -- " + p)
    
#Function: Brew Beer 
#Inputs: Label, Flavor
#Outputs: Prints Steps 
#Returns: String of Beer 
def brewBeer(label, flavor): 
    print("Let's get brewing...")
    print("Step 1: Malting...")
    print("-")    
    print("Ingredients Needed: Barley")
    print("Step 2: Milling...")
    print("--")   
    print("Ingredients Needed: Water")
    print("Step 3: Mashing...")
    print("---")   
    print("Step 4: Lautering...")
    print("----")   
    print("Step 5: Boiling...")
    print("-----")   
    print("Ingredients Needed: Hops")
    print("Step 6: Fermenting...")
    print("------")   
    print("Ingredients Needed: Yeast, ", flavor)
    print("Step 7: Conditioning...")
    print("-------")   
    print("Step 8: Filtering...")
    print("--------")   
    print("Step 9: Time to package and label our freshly brewed beer!...")
    print("----------")   
    return(label + " -- " + flavor)

#Function: Main 
#Inputs: None 
#Outputs: Menu 
#Returns: Int 
def main(): 
    seasonChoice = 0
    packageChoice = 0
    brewedBeer = ""
    i = 0
    #Main Menu
    print("Hi! Let's Brew Some Beer!")

    #Choose Flavor 
    print("First, please choose a seasonal flavor:")
    print("1. Spring: Rose&Strawberry")
    print("2. Summer: Orange&Lemon")
    print("3. Fall: Apple&Cinnamon")
    print("4. Winter: Pine&Maple")
    #Read User Input
    seasonChoice = int(input("So, what do you choose?"))
    #Choose Packaging 
    print("Great! Now let's choose packaging: ")
    print("1. Bottles Only")
    print("2. Cans Only")
    print("3. Let's Do Both :) ")
    #Read User Input 
    packageChoice = int(input("So, what do you choose?"))

    if seasonChoice < 0 or packageChoice < 0 or seasonChoice > 4 or packageChoice > 3: 
        print("Please choose again.")
   
    else: 
        brewedBeer = chooseFlavor(seasonChoice, packageChoice)
    
    print("BREWED BEER")
    print(brewedBeer)
main()