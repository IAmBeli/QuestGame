def analyze_survival():
    try:
        with open ("save.txt", "r") as f:
            lines = f.readlines()
            name = lines[0].strip()
            hp = int(lines[1].strip())
            dmg = int(lines[2].strip())
        print(f"*****AI assistant for {name}*****")
        if hp > 70:
            print("Status: strong. probability of victory: 85%")
        elif hp > 30:
            print("Status: wounded. Probability of victory: 40%. Recommendation: find a potion of healing!")
        else:
            print("Status: critical! Probability of victory: 10%. RUN!")

    except FileNotFoundError:
        print("No save file found for analysis")
    except Exception as e:
            print(f"An error occured: {e}")
analyze_survival()