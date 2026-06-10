import json
import re

def clean_html(raw_html):
    if not isinstance(raw_html, str):
        return ""
    cleanr = re.compile('<.*?>')
    cleantext = re.sub(cleanr, '', raw_html)

    return cleantext.strip()

def get_test_answers(file_path, question_num=None):
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f) # Paste as (r)raw-triple-quoted string + json.loads()
    except FileNotFoundError:
        return f"Error: The file '{file_path}' was not found."
    except json.JSONDecodeError:
        return f"Error: Failed to decode JSON from '{file_path}'."
    
    questions = data.get('allQuestions', [])
    results = []

    for idx, item in enumerate(questions):
        current_q_num = idx + 1 # Using 1-based index as Q-num
        
        # If a specific question number is requested, skip others
        if question_num is not None and current_q_num != question_num:
            continue

        q_obj = item.get('question', {})
        
        # 1. Extract and Clean Question Paragraph
        q_para_html = q_obj.get('questionText', '')
        q_para = clean_html(q_para_html)

        # 2. Extract Correct Answer IDs
        correct_answer_ids = item.get('correctAnswer', [])
        # Ensure it's a list for comparison
        if isinstance(correct_answer_ids, str):
            correct_answer_ids = [correct_answer_ids]
        elif correct_answer_ids is None:
            correct_answer_ids = []
            
        # 3. Collect all options to determine their number (index)
        options_pool = []
        
        # Handle Different Types
        mc_questions = q_obj.get('MultipleChoiceQuestions')
        if mc_questions and isinstance(mc_questions, dict):
            # Extract the list safely
            opts = mc_questions.get('MultipleChoiceOptions', [])
            if isinstance(opts, list):
                options_pool.extend(opts)
             
        tf_questions = q_obj.get('TrueFalseQuestions')
        if tf_questions and isinstance(tf_questions, list):
            options_pool.extend(tf_questions)
             
        correct_options = []
        
        # Enumerate starts at 1.
        for opt_idx, option in enumerate(options_pool, 1):
            if option.get('id') in correct_answer_ids:
                opt_text = clean_html(option.get('optionText', ''))
                correct_options.append(f"{opt_idx}. {opt_text}")
        
        correct_option_str = ", ".join(correct_options)
        
        result = {
            "Q-num": current_q_num,
            "Q-para": q_para,
            "Correct Option": correct_option_str
        }
        results.append(result)
        
        if question_num is not None:
            break
            
    return results

if __name__ == "__main__":
    file_name = 'test.json'
    results = get_test_answers(file_name, 1)
    print("\n")
    for item in results:
        print("Question:", item["Q-num"] , "\n\t" , item["Q-para"])
        print("Correct Option:")
        for option in item["Correct Option"].split(", "):
            print("\t", option)
        print()
        
    print("\n")

    # input_file = 'test.json'
    # output_file = 'clean_test.json'

    # results = get_test_answers(input_file)

    # if isinstance(results, list):
    #     with open(output_file, 'w', encoding='utf-8') as f:
    #         json.dump(results, f, indent=4, ensure_ascii=False)
    #     print(f"Data successfully saved to '{output_file}'")
    # else:
    #     print(results)