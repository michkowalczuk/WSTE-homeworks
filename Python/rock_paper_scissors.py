"""
homework no.1
Rock-paper-scissors-lizard-Spock
Game logic based on: https://en.wikipedia.org/wiki/Rock%E2%80%93paper%E2%80%93scissors#Additional_weapons

@author: Michał Kowalczuk
@date: 2017-05-26
@python: 3.6
"""

import sys
import random

shapes_dict = {"rock": 1, "paper": 2, "scissors": 3, "spock": 4, "lizard": 5}
shapes_list = list(shapes_dict.keys())

# initializing parameters
player_choice = ""
result = ""
player_score = computer_score = games = 0
running = True

# game loop
while running:
    while player_choice not in shapes_list:
        player_choice = input("Type your shape [rock / spock / paper / lizard / scissors]"
                              " or [end] if you want to exit: ").lower()
        if player_choice == "end":
            running = False
            sys.exit()
    computer_choice = random.choice(shapes_list)
    print("Computer choice: {}".format(computer_choice))

    player_choice_id = shapes_dict[player_choice]
    computer_choice_id = shapes_dict[computer_choice]

    games += 1
    # game logic
    operation = (computer_choice_id - player_choice_id) % 5
    if operation == 0:
        result = "TIE"
    elif operation % 2 == 1:
        result = "COMPUTER WIN!"
        computer_score += 1
    else:
        result = "YOU WIN!"
        player_score += 1

    # print results
    print("{:-^50}".format(""))
    print(result)
    print("Game no: {} / Player score: {} / Computer score: {}".format(
        games, player_score, computer_score))
    print("{:=^50}".format(""))

    # Breaking / continuing game
    running = True if input("Try again? [y/n)]: ").lower() == "y" else False
    player_choice = ""
