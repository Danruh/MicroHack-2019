//Canvas stuff
const canvas = new Object();
canvas.element = document.getElementById('canvas');
canvas.context = canvas.element.getContext('2d');
canvas.width = canvas.element.getAttribute('width');
canvas.height = canvas.element.getAttribute('height');
canvas.cellWidth = 10;

//some useful variables about the playarea
var cw = 10; 				//width of the cells
var maxx = (canvas.width/cw) -1; //the maximum allowed position on the grid
var maxy = (canvas.height/cw) - 1 ;//the maximum allowed position on the grid

//these variables represent the state of the game
var d;			//direction of the snake (right, left, up, down)
var food;		//the cell representing the current item of food, has a food.x and food.y position
var score; //the players current score
var snake_array; //an array of cells to make up the snake, each have an x and y position
var obstacle; //this is an obstacle
''
//set it so the init function is called when the page is loaded
window.onload=init;

	function init()
	{
		d = "right"; //default direction


		create_snake(); //build and show the snake
		create_food(); 	//build and show the first food item
		create_obstacle();


		//initialise the score
		score = 0;
		
		//Lets move the snake now using a timer which will trigger 
		//the paint function every 60ms
		if(typeof game_loop != "undefined") clearInterval(game_loop);
		game_loop = setInterval(paint, 60);
	}
	
	//Lets paint the snake now
	function paint()
	{
		//To avoid the snake trail we need to paint the background on every frame
		//Lets paint the canvas 
		canvas.context.fillStyle = "white";
		canvas.context.fillRect(0, 0, canvas.width, canvas.height);
		canvas.context.strokeStyle = "black";
		canvas.context.strokeRect(0, 0, canvas.width, canvas.height);
		
		//update the snakes position based on the current direction
		update_snake(d);
		
		//Lets paint the snake	
		for(var i = 0; i < snake_array.length; i++)
		{
			var c = snake_array[i];
			//Lets paint 10px wide cells
			paint_cell(c.x, c.y);
			console.log("Test");
		}

		//Lets paint the food

        paint_cellO(obstacle.x, obstacle.y);

		paint_cell(food.x, food.y);
        //Lets paint the score
		let score_text = "Score: " + score;
		canvas.context.fillText(score_text, 5, canvas.height-5);

	}
	
	//a generic function to paint cells
	function paint_cell(x, y)
	{
		canvas.context.fillStyle = "green";
		canvas.context.fillRect(x*cw, y*cw, cw, cw);
		canvas.context.strokeStyle = "white";
		canvas.context.strokeRect(x*cw, y*cw, cw, cw);
	}

    function paint_cellO(x, y)
   {
    canvas.context.fillStyle = "red";
    canvas.context.fillRect(x*cw, y*cw, cw, cw);
    canvas.context.strokeStyle = "white";
    canvas.context.strokeRect(x*cw, y*cw, cw, cw);
   }
   function paint_cellP(x, y)
   {
    canvas.context.fillStyle = "black";
    canvas.context.fillRect(x*cw, y*cw, cw, cw);
    canvas.context.strokeStyle = "white";
    canvas.context.strokeRect(x*cw, y*cw, cw, cw);
   }

	
