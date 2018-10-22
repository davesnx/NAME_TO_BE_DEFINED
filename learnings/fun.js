const expect = (a, b) => {
  if (a !== b) {
    console.error('a => ', a)
    console.error('      is different than')
    console.error('b => ', b)
  } else {
    console.log('OK')
  }
}

function saludar (nombre, num) {
  let saludoRepe = ''

  for (let i = 0; i < num; ++i) {
    const todosMenosElUltimo = i < num - 1
    saludoRepe = saludoRepe + 'Hola ' + nombre + '!'

    if (todosMenosElUltimo) {
      saludoRepe = saludoRepe + ', '
    }
  }

  return saludoRepe
}

const saludo = saludar('Adriana', 3)

expect(saludo, 'Hola Adriana!, Hola Adriana!, Hola Adriana!')
