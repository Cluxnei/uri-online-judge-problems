def lp(copy, original):
    copy_len = len(copy)
    original_len = len(original)
    if copy_len > original_len:
        return original_len - 1
    return copy_len - 1 if original_len == copy_len else copy_len


def not_flat_or_sharp(char):
    return char != '#' and char != 'b'


def transpose_note(note, notes):
    if note == 'E#':
        return 'F#'
    if note == 'B#':
        return 'C#'
    if note == 'B':
        return 'C'

    current_index = notes.index(note)
    if current_index == len(notes) - 1:
        current_index = -1
    return notes[current_index + 1]


def transpose_copy(copy_notes):
    # Declare the notes
    notes_asc = ['C', 'C#', 'D', 'D#', 'E', 'E#', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'B#']
    # Split notes of copy
    transpose_copy_notes = ''
    first_iterations = True
    for note in copy_notes.split(' '):
        transpose_copy_notes += ('' if first_iterations else ' ') + transpose_note(note, notes_asc)
        first_iterations = False
    return transpose_copy_notes


def transpose_copy_down(copy_notes):
    # Declare the notes
    notes_desc = ['C', 'Cb', 'B', 'Bb', 'A', 'Ab', 'G', 'Gb', 'F', 'Fb', 'E', 'Eb', 'D', 'Db']
    # Split notes of copy
    transpose_copy_notes = ''
    first_iterations = True
    for note in copy_notes.split(' '):
        transpose_copy_notes += ('' if first_iterations else ' ') + transpose_note(note, notes_desc)
        first_iterations = False
    return transpose_copy_notes


# Infinity loop
while True:
    # Read line
    line = input().split(' ')
    # Get the length of musics
    num_original = int(line[0])
    num_copy = int(line[1])
    # Check if is end of program
    if num_copy == num_original and num_copy == 0:
        break
    # Read the original
    original = input()
    # Read the copy
    copy = input()

    # Check if copy is substring of original and last char is not # or b
    last_char_of_substr = original[lp(copy, original)]
    if copy in original and not_flat_or_sharp(last_char_of_substr):
        print('S')
        continue

    # Transpose copy 1 time up and check substring of original
    is_copy = False
    transposed_copy = transpose_copy(copy)
    without_spaces_transposed_copy = ''.join(transposed_copy.split(' '))
    without_spaces_original = ''.join(original.split(' '))
    last_char_of_substr = without_spaces_original[lp(without_spaces_transposed_copy, without_spaces_original)]
    if without_spaces_transposed_copy in without_spaces_original and not_flat_or_sharp(last_char_of_substr):
        print('S')
        continue
    # Transpose copy 12 times and check substring of original
    for i in range(1, 12):
        # print(transposed_copy, '|||###########||||', transpose_copy(transposed_copy))
        # Transpose the transposition
        transposed_copy = transpose_copy(transposed_copy)
        # Remove spaces from transposition
        without_spaces_transposed_copy = ''.join(transposed_copy.split(' '))
        # Get last char of original after length of transposed copy
        last_char_of_substr = without_spaces_original[lp(without_spaces_transposed_copy, without_spaces_original)]
        # Check if is substr and not # or b
        if without_spaces_transposed_copy in without_spaces_original and not_flat_or_sharp(last_char_of_substr):
            is_copy = True
            break
    # If not a copy check 1 time down
    if not is_copy:
        transposed_copy = transpose_copy_down(copy)
        without_spaces_transposed_copy = ''.join(transposed_copy.split(' '))
        last_char_of_substr = without_spaces_original[lp(without_spaces_transposed_copy, without_spaces_original)]
        if without_spaces_transposed_copy in without_spaces_original and not_flat_or_sharp(last_char_of_substr):
            print('S')
            continue
        # Check 12 times down
        for i in range(0, 12):
            # print(transposed_copy, '|||bbbbbbbbb||||', transpose_copy(transposed_copy))
            transposed_copy = transpose_copy_down(transposed_copy)
            without_spaces_transposed_copy = ''.join(transposed_copy.split(' '))
            last_char_of_substr = without_spaces_original[lp(without_spaces_transposed_copy, without_spaces_original)]
            if without_spaces_transposed_copy in without_spaces_original and not_flat_or_sharp(last_char_of_substr):
                is_copy = True
                break
    # # Puts the output
    print('S' if is_copy else 'N')
