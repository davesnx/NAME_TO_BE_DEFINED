import React, { Component } from 'react'

class App extends Component {
  constructor (props) {
    super(props)

    this.state = {
      inputValue: '',
      capricho: []
    }
  }

  render () {
    return (
      <div>
        <header>
          <h1>
            whimapp
          </h1>
          <p>
            Slogan to wuapo
          </p>
        </header>
        <input
          type='text'
          value={this.state.inputValue}
          placeholder='Type your whim'
          onChange={event => {
            this.setState({ inputValue: event.target.value })
          }}
        />
        <button
          onClick={() => {
            this.setState({
              inputValue: '',
              capricho: this.state.capricho.concat(this.state.inputValue)
            })
          }}
        />
        <p>
          {JSON.stringify(this.state.capricho)}
        </p>
      </div>
    )
  }
}

export default App
