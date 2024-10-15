import json

class Story:
    def __init__(self):
        self.story = {}
        self.current_segment_id = 0

    def load_story(self, story_file) -> None:
        with open(story_file, 'r') as f:
            self.story = json.load(f)
        self.current_segment_id = 1

    def print_current_segment(self) -> None:
        print(self.story[str(self.current_segment_id)]['description'])

        for i, choice in enumerate(self.story[str(self.current_segment_id)]['choices']):
            print(f'{i+1}. {self.story[str(self.current_segment_id)]['choices'][choice]}')

    def next_segment(self, choice: int) -> None:
        self.current_segment_id = self.story[str(self.current_segment_id)]['nextSegmentIds'][str(choice)]

story = Story()
story.load_story('assets/quests/plot.json')
story.print_current_segment()

while (True):
    user_choice = int(input('Enter your choice: '))
    story.next_segment(user_choice)
    story.print_current_segment()
