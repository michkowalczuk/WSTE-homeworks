# Pygame template - skeleton for a new pygame project
from builtins import property

import pygame
from pygame import Color
# import random
import os
import numpy as np
from enum import Enum

# center window position
os.environ['SDL_VIDEO_CENTERED'] = '1'  # must be before pygame.init()!

BLUE = Color('blue')
BLACK = Color('black')
GREY = Color('grey')
RED = Color('red')
WHITE = Color('white')
BROWN = Color('brown')
ORANGE = Color('orange')


FONT_NAME = pygame.font.match_font('arial')
FONT_SIZE = 16

WIDTH = 1000
HEIGHT = 600
FPS = 30
TILE_SIZE = 40
MARGIN_X = 40
MARGIN_Y = 40


TILE_X = [i * TILE_SIZE + MARGIN_X for i in range(10)]
TILE_Y = [i * TILE_SIZE + MARGIN_Y for i in range(10)]

class TextAlign(Enum):
    CENTER = 1
    MIDLEFT = 2
    MIDRIGHT = 3
    TOPLEFT = 3
    TOPRIGHT=4

class TileType(Enum):
    NONE = 0
    MAST_1 = 1
    MAST_2 = 2
    MAST_3 = 3
    MAST_4 = 4
    INPUT = -1

class Tile(pygame.sprite.Sprite):
    player = None
    def __init__(self, index, position, *groups):
        pygame.sprite.Sprite.__init__(self, *groups)  # must be!
        self.image = pygame.Surface((TILE_SIZE-1, TILE_SIZE-1))
        self.image.fill(WHITE)
        self.rect = self.image.get_rect()
        self.rect.left = position[0]
        self.rect.top = position[1]
        self.index = index
        # self.player = player
        self.isMouseover = False
        # self.type = TileType.NONE

    # @property
    # def i(self):
    #     return self.index[0]
    #
    # @property
    # def j(self):
    #     return self.index[1]

    def update(self):
        # print(Tile.player.board)
        if self.isMouseover:
            self.image.fill(RED)
        else:
            if Tile.player.board[self.index[1], self.index[0]] in range(1,5):
                self.image.fill(BLUE)
            else:
                self.image.fill(WHITE)


class Player(object):
    def __init__(self):
        self.board = np.zeros((10,10))

    def mast_count(self, n):
        return int(np.count_nonzero(self.board == n) / n)

    @property
    def fleet_complete(self):
        # return (self.mast_count(5) == 0 )
        return all([(self.mast_count(i) == 5 - i) for i in range(1,5)])

    def setShip(self, n, index):
        self.board[index[1], index[0]] = n


def draw_text(surf, text, size, x, y, align=TextAlign.CENTER):
    font = pygame.font.Font(FONT_NAME, size)
    text_surface = font.render(text, True, BLACK)
    text_rect = text_surface.get_rect()
    if align == TextAlign.CENTER:
        text_rect.center = (x, y)
    elif align == TextAlign.MIDLEFT:
        text_rect.midleft = (x, y)
    elif align == TextAlign.MIDRIGHT:
        text_rect.midright = (x, y)
    elif align == TextAlign.TOPLEFT:
        text_rect.topleft = (x, y)
    elif align == TextAlign.TOPRIGHT:
        text_rect.topright = (x, y)
    surf.blit(text_surface, text_rect)

def draw_board(surf, offset=0):
    for i, x in TILE_X:
        for y in TILE_Y:
            draw_tile(surf, x + offset, y)

    for i, x in enumerate(TILE_X):
        draw_text(surf, chr(65 + i), FONT_SIZE, x + TILE_SIZE/2 + offset, MARGIN_Y - TILE_SIZE/2)

    for i, y in enumerate(TILE_Y):
        draw_text(surf, str(i + 1), FONT_SIZE, MARGIN_X - TILE_SIZE/2 + offset, y + TILE_SIZE/2)

def draw_tile(surf, x, y):
    tile_rect = pygame.Rect(x, y, TILE_SIZE, TILE_SIZE)
    pygame.draw.rect(surf, WHITE, tile_rect)
    pygame.draw.rect(surf, BLUE, tile_rect, 1)


def draw_horizontal_line(surf, x):
    pygame.draw.line(surf, BLUE, (x, TILE_Y[0]), (x, TILE_Y[-1] + TILE_SIZE))


def draw_vertical_line(surf, x):
    pygame.draw.line(surf, BLUE, (x, TILE_Y[0]),(x, TILE_Y[-1]))


# INITIALIZE PYGAME AND CREATE WINDOW
pygame.init()
pygame.mixer.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("WSTE Battleship")
clock = pygame.time.Clock()

all_sprites = pygame.sprite.Group()
# tile = Tile(all_sprites)


for i, x in enumerate(TILE_X):
    for j, y in enumerate(TILE_Y):
        tile = Tile((i,j), (x, y), all_sprites)
        all_sprites.add(tile)

player = Player()
Tile.player = player

# GAME LOOP
# instructions = True
running = True
x,y = 0, 0
mouseClicked = False
clickedTileIndex = []
while running:

    # keep loop running at the right speed
    clock.tick(FPS)

    mouseClicked = False

    # PROCESS INPUT (EVENTS)
    for event in pygame.event.get():
        # check for closing window
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEMOTION:
            (x,y) = event.pos

        elif event.type == pygame.MOUSEBUTTONDOWN:
            (x, y) = event.pos
            if event.button == 1:
                mouseClicked = True


    # UPDATE
    all_sprites.update()

    for tile in all_sprites:
        if tile.rect.collidepoint(x,y):
            # print((x,y))
            tile.isMouseover = True
            if mouseClicked:
                clickedTileIndex = tile.index
            #     player.SetShip(i, tile.index)
            #     print(player.board)
        else:
            tile.isMouseover = False
            # print("nnn")


    # DRAW / RENDER
    screen.fill(GREY)
    all_sprites.draw(screen)

    # draw_board_lines(screen, )

    # draw_board(screen)  # player's board
    # draw_board(screen, 500)  # computer's board
    # draw_tile(screen, 20, 30)

    # for tile in all_sprites:
    #     if tile.rect.collidepoint(x,y):
    #         print((x,y))
    #         tile.isMouseover = True
    #         # pygame.draw.rect(screen, RED, tile.rect, 2)
    #         # tile.image.fill(RED)
    #         # print("ttt")
    #     else:
    #         tile.isMouseover = False
    #         # print("nnn")

    # input fleet part
    if not player.fleet_complete:
        instructions =["Wprowadz:"]
        for i in range(1,5):
            if player.mast_count(i) != 5 - i:
                instructions.append("{} x {}-maszt".format((5 - i) - player.mast_count(i), i))
                if mouseClicked:
                    player.setShip(i, clickedTileIndex)
                    # print(player.board)
                break
        for i, instruction in enumerate(instructions):
            x_instruction = MARGIN_X
            y_instruction = TILE_Y[-1] + TILE_SIZE + MARGIN_Y/2 + i * TILE_SIZE/2

            draw_text(screen, instruction, FONT_SIZE, x_instruction, y_instruction, TextAlign.MIDLEFT)

    # *after* drawing everything, flip the display
    pygame.display.flip()

pygame.quit()
