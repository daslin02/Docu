import json
from docx import Document
from sys import argv


def load_data(file_name):
    with open(file_name, 'r', encoding='utf-8') as file:
        return json.load(file)

def create_word_table(data, output_file):
    doc = Document()
    headers = ["Название продукта", "Дата", "Количество", "Единица измерения"]
    table = doc.add_table(rows=1, cols=len(headers))
    hdr_cells = table.rows[0].cells

    for i, header in enumerate(headers):
        hdr_cells[i].text = header

    for item in data:
        row_cells = table.add_row().cells
        row_cells[0].text = item['name']
        row_cells[1].text = item['data']
        row_cells[2].text = str(item['surplus'])  # Используем 'surplus' вместо 'count'
        row_cells[3].text = item['unit']
    
    doc.save(output_file)

def main():
    script, file_name, save = argv
    output_file = save     
    data = load_data(file_name)

    analyzed_data = []
    for item in data:
        analyzed_data.append({
            'name': item['name'],
            'data': item['data'],
            'surplus': item['surplus'],  # Используем 'surplus' вместо 'count'
            'unit': item['unit']
        })
    create_word_table(analyzed_data, output_file)
    print(f"Отчет успешно создан: {output_file}")

if __name__ == "__main__":
    main()
