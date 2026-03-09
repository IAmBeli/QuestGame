import csv
import os
import matplotlib.pyplot as plt
def plothistory():
    try:
        levels = []
        hp_values = []
        gold_values = []
        with open("history.csv", "r") as f:
            reader = csv.DictReader(f)
            for row in reader:
                levels.append(len(levels) + 1)
                hp_values.append(int(row["HP"]))
                gold_values.append(int(row["Gold"]))
        plt.figure(figsize=(10, 5))
        plt.plot(levels, hp_values, label="Health (HP)", color="red", marker="o")
        plt.plot(levels, gold_values, label="Gold", color="gold", marker="s")
        plt.title("Hero progress over time")
        plt.xlabel("Game session")
        plt.ylabel("Value")
        plt.legend()
        plt.grid(True)
        print("Showing progress chart...")
        plt.show()
    except Exception as e:
        print(f"Could not plot data: {e}. try playing more sessions first!")
def loggamedata():
    try:
        with open("save.txt", "r") as f:
            lines = f.readlines()
            if len(lines) < 5: return
            data = [line.strip() for line in lines]
        file_exists = os.path.isfile("history.csv")
        with open("history.csv", "a", newline="") as f:
            writer = csv.writer(f)
            if not file_exists:
                writer.writerow(["Name", "HP", "Damage", "Gold", "Level"])
            writer.writerow(data)
        print("-> Game session logged to history.csv")
    except Exception as e:
        print(f"Logging failed due to: {e}")
def analyze_survival():
    try:
        with open ("save.txt", "r") as f:
            lines = f.readlines()
            name = lines[0].strip()
            hp = int(lines[1].strip())
            dmg = int(lines[2].strip())
            gold = int(lines[3].strip())
            level = int(lines[4].strip())
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
        if level > 2:
             print("Status: experienced adventurer.")
        else:
             print("Status: Novice. You are still at the beginning of your journey.")
    except FileNotFoundError:
        print("No save file found for analysis")
    except Exception as e:
            print(f"An error occured: {e}")
analyze_survival()
loggamedata()
plothistory()