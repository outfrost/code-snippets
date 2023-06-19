class_name DebugLabel
extends Label

var buffer: String = ""

func _ready():
	text = ""

func _process(_delta):
	text = buffer
	buffer = ""

func display_impl(s: String):
	buffer += s + "\n"

static func display(ref, s):
	var label = ref.get_tree().root.find_node("DebugLabel", true, false) as DebugLabel
	if label:
		label.display_impl(s)
