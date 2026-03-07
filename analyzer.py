def analyze_survival():
    try:
        with open ("save.txt", "r") as f:
            lines = f.readlines()
            name = lines[0].strip()
            hp = int(lines[1].strip())
            dmg = int(lines[2].strip())
            gold = int(lines[3].strip())
            level = int(lines[4].stripe())
        print(f"*****Strategy report for {name}*****")
        efficiency = gold / (101 - hp)
        if hp > 70:
            print("Status: strong. probability of victory: 85%")
        elif hp > 30:
            print("Status: wounded. Probability of victory: 40%. Recommendation: find a potion of healing!")
        else:
            print("Status: critical! Probability of victory: 10%. RUN!")
        if efficiency < 1.0:
             print("Advice: you take too much damage for too little gold. Buy more potions!")
        elif efficiency:
             print("Advice: great strategy! You are a profitable warrior!")
    except FileNotFoundError:
        print("No save file found for analysis")
    except Exception as e:
            print(f"An error occured: {e}")
analyze_survival()