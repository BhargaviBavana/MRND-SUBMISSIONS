import pygame
from pygame.locals import *
pygame.init()

def main():
    clock = pygame.time.Clock()
    screen=pygame.display.set_mode((300,400))
    done = False
    color=(50,100,150)
    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True
        screen.blit(pygame.image.load("bomb.gif").convert,(0,0))
        clock.tick(100)
        pygame.display.flip()


if __name__=="__main__":
    SCREENRECT = Rect(0, 0, 640, 480)
    print(SCREENRECT.size)
    main()