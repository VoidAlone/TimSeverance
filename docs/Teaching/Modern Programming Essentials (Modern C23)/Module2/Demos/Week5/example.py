class Enemy:
    def __init__(self):
        self.health = 120
        self.attack = 10

enemy_queue = []

def queue_enemy(en: Enemy) -> void:
    enemy_queue.append(en)

def main():
    en1 = Enemy()
    en2 = Enemy()
    queue_enemy(en1)
