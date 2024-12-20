import json
from docx import Document
from sys import argv


script, file_name, save = argv[0], argv[1], argv[2]


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
        row_cells[2].text = str(item['count'])
        row_cells[3].text = item['unit']

    doc.save(output_file)


def main():
    json_file = file_name 
    output_file = save     

    data = load_data(json_file)

    analyzed_data = []
    for product in data:
        for arr in product['prihod'][0]:
            analyzed_data.append({
                'name': product['name'],
                'data': arr['data'],
                'count': arr['count'],
                'unit': arr['unit']
            })
        for arr in product['rashod'][0]:
            analyzed_data.append({
                'name': product['name'],
                'data': arr['data'],
                'count': -arr['count'],  
                'unit': arr['unit']
            })

    create_word_table(analyzed_data, output_file)
    print(f"Отчет успешно создан: {output_file}")

if __name__ == "__main__":
    main()
