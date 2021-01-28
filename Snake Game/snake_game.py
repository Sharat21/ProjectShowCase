
import pygame
import time
import random

pygame.init()

snake = (210, 87, 27)
white = (229,235,235)
yellow = (234, 235, 116)
black = (0,0,0)
red = (234, 50, 48)
green = (26, 185, 48)
background = (28, 27, 27)



Grid_Width = 600
Grid_Length = 400

dis = pygame.display.set_mode((Grid_Width, Grid_Length))
pygame.display.set_caption("Hungry Snake by Sharat Krishnan - SK")
clock = pygame.time.Clock()

snake_block = 10
snake_speed = 15

font_style = pygame.font.SysFont("bahnschrift",25)
score_font = pygame.font.SysFont("comicsansms",35)


def player_score(score):
	value = score_font.render("  Score: " + " " +  str(score), True, white)
	dis.blit(value, [0,0])

def our_snake(snake_block, snake_list):
	for i in snake_list:
		pygame.draw.rect(dis, snake, [i[0],i[1], snake_block, snake_block])

def message(msg, color):
	mesg = font_style.render(msg, True, color)
	dis.blit(mesg, [Grid_Width/6, Grid_Length/3 ])

def game_menu():
	game_close = False
	while game_close == False:
		for event in pygame.event.get():
			if not  event.type == pygame.KEYDOWN:
				dis.fill(background)
				message("Press Any Key to Start or ESC to Exit", white)
				pygame.display.update()
			else:
				main()


def main():
	game_over = False
	game_close = False

	x1 = Grid_Width/2
	y1 = Grid_Length/2

	x1_change = 0
	y1_change = 0

	snake_List = []
	snake_length = 1

	foodx = round(random.randrange(0, Grid_Width - snake_block) / 10.0) * 10.0
	foody = round(random.randrange(0, Grid_Length - snake_block) / 10.0) * 10.0

	while not game_over:
		while game_close == True:
			dis.fill(background)
			message("You Lost! Press C-Play Again or Q-Quit", red)

			pygame.display.update()

			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_q:
						game_over = True
						game_close = False
					if event.key == pygame.K_c:
						main()
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				game_over == True
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_LEFT:
					x1_change = -snake_block
					y1_change = 0
				elif event.key == pygame.K_a:
					x1_change = -snake_block
					y1_change = 0
				elif event.key == pygame.K_RIGHT:
					x1_change = snake_block
					y1_change = 0
				elif event.key == pygame.K_d:
					x1_change = snake_block
					y1_change = 0
				elif event.key == pygame.K_UP:
					y1_change = -snake_block
					x1_change = 0
				elif event.key == pygame.K_w:
					y1_change = -snake_block
					x1_change = 0
				elif event.key == pygame.K_DOWN:
					y1_change = snake_block
					x1_change = 0
				elif event.key == pygame.K_s:
					y1_change = snake_block
					x1_change = 0
				elif event.key == pygame.K_ESCAPE:
					game_over = True
		if  x1 >= Grid_Width or x1 < 0 or y1 >= Grid_Length or y1 < 0:
			game_close = True
		x1 += x1_change
		y1 += y1_change
		dis.fill(background)
		pygame.draw.rect(dis, red, [foodx, foody, snake_block,  snake_block])
		snake_Head = []
		snake_Head.append(x1)
		snake_Head.append(y1)
		snake_List.append(snake_Head)
		if len(snake_List) > snake_length:
			del snake_List[0]

		for n in snake_List[:-1]:
			if n == snake_Head:
				game_close = True

		our_snake(snake_block,snake_List)
		player_score(snake_length - 1)

		pygame.display.update()

		if x1 == foodx and y1 == foody:
			foodx = round(random.randrange(0,Grid_Width - snake_block) / 10.0) *10.0
			foody = round(random.randrange(0,Grid_Length - snake_block) / 10.0) *10.0
			snake_length += 1

		clock.tick(snake_speed)

	pygame.quit()
	quit()
game_menu()
