$doxydocs=
{
  classes => [
    {
      name => 'ActionCard',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'ActionCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'countryA',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'countryB',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'letter',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'number',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'season',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'sprite_offset_left',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'sprite_offset_right',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ActionCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new Action Card. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'type'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The type of card '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'countryA'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The name of the left side (Either a country or type of wild card) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'countryB'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The name of the right side (Either a country of blank) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'season'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The season the card commands in with priority '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'letter'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The letter the card commands in with priority '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'number'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The number the card commands in with priority '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'sprite_offset_left'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The uncalculated sprite index of the left sprite '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'sprite_offset_right'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The uncalculated sprite index of the right sprite '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'type',
                type => 'const ActionType'
              },
              {
                declaration_name => 'countryA',
                type => 'const string'
              },
              {
                declaration_name => 'countryB',
                type => 'const string'
              },
              {
                declaration_name => 'season',
                type => 'const Season'
              },
              {
                declaration_name => 'letter',
                type => 'const char'
              },
              {
                declaration_name => 'number',
                type => 'const size_t'
              },
              {
                declaration_name => 'sprite_offset_left',
                type => 'const size_t'
              },
              {
                declaration_name => 'sprite_offset_right',
                type => 'const size_t'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The type of Action Card (DIPLOMACY for specific countries or a WILD) '
                }
              ]
            },
            type => 'ActionType'
          },
          {
            kind => 'variable',
            name => 'countryA',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The left country that could be influenced or the name of the wild card '
                }
              ]
            },
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'countryB',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The second country that could be influenced (blank for wild) '
                }
              ]
            },
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'season',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The command season the player has priority for '
                }
              ]
            },
            type => 'Season'
          },
          {
            kind => 'variable',
            name => 'letter',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The command letter for priority (Z>A) '
                }
              ]
            },
            type => 'char'
          },
          {
            kind => 'variable',
            name => 'number',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The number command for priority (9>0) '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'sprite_offset_left',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite index of the left country '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'sprite_offset_right',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite index of the right country '
                }
              ]
            },
            type => 'size_t'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'App',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'renderer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        },
        {
          name => 'screen',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        },
        {
          name => 'window',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'window',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Window *'
          },
          {
            kind => 'variable',
            name => 'renderer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Renderer *'
          },
          {
            kind => 'variable',
            name => 'screen',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Graphics::Screen'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'City',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Map.h'
      },
      all_members => [
        {
          name => 'addUnit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'aggresor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'blockcade',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'City',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'City',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'city_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'country',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'country_counts',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'full_display',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getEnemy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getFirst',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getID',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getLast',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getName',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getNext',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getPrev',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'HEIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'ID',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'influence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'influencer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'isConflict',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'isEnemy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'last_skip',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'loopVal',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'med_blockcade',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'muster',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'nationality',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'num_occupants',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'numEnemies',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'occupants',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'population',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'population_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'power_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'printOccupants',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'removeUnit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'res_x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'res_y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'resource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'resource_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'ruler_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'season_supplied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'skip_troop',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'supllied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'WIDTH',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'year_supplied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'City',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'struct_city',
                  content => 'City'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ID'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'id of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Name of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The starting allegiance of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'power_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The power of the city (GREAT, HOME, MINOR, NONE) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'population'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The pop value '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'muster'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'How many troops are added when taken over '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resource'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'How many resources given '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resource_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The type of resource (N is none as well) '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ID',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'name',
                type => 'const string',
                default_value => '"City"'
              },
              {
                declaration_name => 'city_type',
                type => 'const CityType',
                default_value => 'WATER'
              },
              {
                declaration_name => 'power_type',
                type => 'const PowerType',
                default_value => 'NONE'
              },
              {
                declaration_name => 'population_type',
                type => 'const PopulationType',
                default_value => 'EMPTY'
              },
              {
                declaration_name => 'nationality',
                type => 'const UnitCountry',
                default_value => 'NEUTRAL_U'
              },
              {
                declaration_name => 'population',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'muster',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'resource',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'resource_type',
                type => 'const ResourceType',
                default_value => 'NORMAL'
              }
            ]
          },
          {
            kind => 'function',
            name => 'City',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'height',
                type => 'const int'
              },
              {
                declaration_name => 'width',
                type => 'const int'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'ID',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'name',
                type => 'const string',
                default_value => '"City"'
              }
            ]
          },
          {
            kind => 'function',
            name => 'isConflict',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If there currently a battle going on (more than one allegiance of troops) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true There is a battle '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false There is no battle (friendly troops or empty) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'isEnemy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Returns if the opposing troops are together. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the troop entering '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true There is enemies '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false No enemies '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'numEnemies',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gives the number of enemies (not the number of units) in the current city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the unit '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t how many enemeis in the city depending on the unit\'s allegiance '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getEnemy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'In the case where there is only one enemy return the one there. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the attacker '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'CityType The defender '
                    }
                  ]
                }
              ]
            },
            type => 'CityType',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'removeUnit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Removes a unit form this city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit to remove '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addUnit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a unit to this city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit to add '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'printOccupants',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getFirst',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'curr',
                type => 'int &'
              },
              {
                declaration_name => 'allegiance_viewing',
                type => 'CityType &'
              },
              {
                declaration_name => 'selected_unit',
                type => 'Unit **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getLast',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'curr',
                type => 'int &'
              },
              {
                declaration_name => 'allegiance_viewing',
                type => 'CityType &'
              },
              {
                declaration_name => 'selected_unit',
                type => 'Unit **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNext',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'curr',
                type => 'int &'
              },
              {
                declaration_name => 'allegiance_viewing',
                type => 'CityType &'
              },
              {
                declaration_name => 'selected_unit',
                type => 'Unit **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getPrev',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'curr',
                type => 'int &'
              },
              {
                declaration_name => 'allegiance_viewing',
                type => 'CityType &'
              },
              {
                declaration_name => 'selected_unit',
                type => 'Unit **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'loopVal',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'val',
                type => 'const int'
              },
              {
                declaration_name => 'min_val',
                type => 'const int'
              },
              {
                declaration_name => 'max_val',
                type => 'const int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getName',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getID',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints out all attributes of the city. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'HEIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'For graphics. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The height of the city when rendered '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'WIDTH',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The width of the city when rendered '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The x origin of the city shape '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The y origin of the city shape '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'res_x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The x origin of the cities resources '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'res_y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The y origin of the cities resources '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'skip_troop',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When cities are shown the troop to start showing is at the index of the players nationality '
                }
              ]
            },
            type => 'int',
            arguments => '[3]',
            initializer => '= {0, 0, 0}'
          },
          {
            kind => 'variable',
            name => 'last_skip',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Every 10 seconds update the skip units count '
                }
              ]
            },
            type => 'Uint32',
            arguments => '[3]',
            initializer => '= {0, 0, 0,}'
          },
          {
            kind => 'variable',
            name => 'full_display',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            initializer => '= false'
          },
          {
            kind => 'variable',
            name => 'ID',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The ID of the city '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The name of the city '
                }
              ]
            },
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'country',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which larger country it belongs too '
                }
              ]
            },
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'city_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'What type of power it starts as (West, Axis, Ussr) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'power_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Whats the power level of the city (great, home...) '
                }
              ]
            },
            type => 'PowerType'
          },
          {
            kind => 'variable',
            name => 'ruler_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current ruler of the city (origionally set to the city_type until conquered) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'population_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The type of city population (capital, city, town...) '
                }
              ]
            },
            type => 'PopulationType'
          },
          {
            kind => 'variable',
            name => 'nationality',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The nationality of the city (different from country where non-powers is neutral) '
                }
              ]
            },
            type => 'UnitCountry'
          },
          {
            kind => 'variable',
            name => 'population',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The population (pop) of the city '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'muster',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The muster determines how much troops are gained when influnced or strength of neutral forces when invaded '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The amount of resources this city provides (mixed resources are always halfed so can be stored as one) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resource_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'ResourceType'
          },
          {
            kind => 'variable',
            name => 'blockcade',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'What type of resource is on this city (only matters for blockades and going around Africa) If the city is unable to be traced back to the main capital '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          },
          {
            kind => 'variable',
            name => 'med_blockcade',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the city is unable to be traced back to the main capital, BUT the red resource is able to go around africa '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          },
          {
            kind => 'variable',
            name => 'occupants',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral '
                }
              ]
            },
            type => 'vector< Unit * >',
            arguments => '[4]'
          },
          {
            kind => 'variable',
            name => 'country_counts',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            arguments => '[7]',
            initializer => '= {0, 0, 0, 0, 0, 0, 0}'
          },
          {
            kind => 'variable',
            name => 'num_occupants',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'influence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The amount of influence on this country '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'influencer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The power who has the current influence over a starting neutral country (neutral if no influence) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'aggresor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The Attacker is the Faction provoking Combat in that '
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' Turn (the Active player). This is not the same as the Aggressor (the Faction trying to wrest control of a Land Area from the Owner) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'year_supplied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'season_supplied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Season'
          },
          {
            kind => 'variable',
            name => 'supllied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            initializer => '=false'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Each segment of the map where troops can be stationed. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Country',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'addCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'added_influence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'allegiance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'capital',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'cities',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'Country',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'getName',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'id',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'influence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'influence_level',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'pushback',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'resolveCards',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'resolveDiplomacy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        },
        {
          name => 'top_card',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Country'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Country',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'struct_country',
                  content => 'Country'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of the country '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'influence_level'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The satelite state of this country (UNALIGNED, ASSOCIATES, PROTECTORATES, SATELLITES) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'influence'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The current influnce level of the country [0...3] '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              },
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'capital',
                type => 'const string'
              },
              {
                declaration_name => 'influence_level',
                type => 'const InfluenceType',
                default_value => 'UNALIGNED'
              },
              {
                declaration_name => 'influence',
                type => 'const int',
                default_value => '0'
              }
            ]
          },
          {
            kind => 'function',
            name => 'pushback',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'influencer',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'resolveCards',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'resolveDiplomacy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getName',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'id',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'capital',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'allegiance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType',
            initializer => '=WATER'
          },
          {
            kind => 'variable',
            name => 'influence_level',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'InfluenceType'
          },
          {
            kind => 'variable',
            name => 'influence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'added_influence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'top_card',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType',
            initializer => '=WATER'
          },
          {
            kind => 'variable',
            name => 'cities',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'vector< City * >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Dice',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'Dice',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'Dice',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'max',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'min',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'roll',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'stats',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Dice',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a default dice where the only possible value is 0. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Dice',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new dice with a given min and max value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'min'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The mininum value the dice can roll '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'max'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The maximum value the dice can roll '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'min',
                type => 'int'
              },
              {
                declaration_name => 'max',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'roll',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Returns a value between the min and max value (inclusive, inclusive) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'int The value of the die '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints out the frequency of each possible dice roll. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'stats',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Vector to hold how often each side was rolled '
                }
              ]
            },
            type => 'vector< int >'
          },
          {
            kind => 'variable',
            name => 'min',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Min value of the die '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'max',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Max value of the die '
                }
              ]
            },
            type => 'int'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'IMG_Animation',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'SDL_image.h'
      },
      all_members => [
        {
          name => 'count',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IMG_Animation'
        },
        {
          name => 'delays',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IMG_Animation'
        },
        {
          name => 'frames',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IMG_Animation'
        },
        {
          name => 'h',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IMG_Animation'
        },
        {
          name => 'w',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IMG_Animation'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'w',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'h',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'count',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'frames',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Surface **'
          },
          {
            kind => 'variable',
            name => 'delays',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int *'
          }
        ]
      },
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Animated image support Currently only animated GIFs are supported. '
          }
        ]
      }
    },
    {
      name => 'InvestmentCard',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'amount',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'InvestmentCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'sprite_offset_left',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'sprite_offset_right',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'tech1',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'tech2',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'year',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'InvestmentCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new Investment Card object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'type'
                        }
                      ],
                      doc => [
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'tech1_name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'tech2_name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'amount'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'year'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'sprite_offset_left'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'sprite_offset_right'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'type',
                type => 'const InvestType'
              },
              {
                declaration_name => 'tech1_name',
                type => 'const string'
              },
              {
                declaration_name => 'tech2_name',
                type => 'const string'
              },
              {
                declaration_name => 'amount',
                type => 'const int'
              },
              {
                declaration_name => 'year',
                type => 'const size_t'
              },
              {
                declaration_name => 'sprite_offset_left',
                type => 'const size_t'
              },
              {
                declaration_name => 'sprite_offset_right',
                type => 'const size_t'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The type of invest Card (the basic two sided TECHNOLOGY card, or a wild effect INTELLIGENCE, or a wild YEAR card) '
                }
              ]
            },
            type => 'InvestType'
          },
          {
            kind => 'variable',
            name => 'tech1',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< The name of the left side of the tech (or the year it\'s usable) '
                }
              ]
            },
            type => 'Technology'
          },
          {
            kind => 'variable',
            name => 'tech2',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The name of the right side of the tech (blank for INTELLIGENCE cards) '
                }
              ]
            },
            type => 'Technology'
          },
          {
            kind => 'variable',
            name => 'amount',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The value the card contributes to raising the industry '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'year',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The year of the YEAR card it applies too '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'sprite_offset_left',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite index of the left tech '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'sprite_offset_right',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite index of the right tech '
                }
              ]
            },
            type => 'size_t'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Map',
      kind => 'class',
      inner => [
      ],
      all_members => [
        {
          name => 'addCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'addCountry',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'adjacency',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'checkConnection',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'cities',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'city_masterlist',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'connect',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'countries',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'findCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getAdjacency',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCapital',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCities',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getClosestCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCountries',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCountry',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getNumCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'initLists',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'list_size',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'operator[]',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'operator[]',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'sortedX',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'sortedY',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'initLists',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes the adjacency list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'size'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The amount of cities and ultimate the side length of it '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'size',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addCountry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a country pointer to the map. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'country'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The country being added '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'country',
                type => 'Country *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a city pointer to the map and master list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new city '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator[]',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'overloads [] such that the hash map can be accessed from outside the scope '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'target'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The name of the city that acts as the key '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The city with the given name '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'target',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator[]',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Returns the city form the ML at the index (id) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'id'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The id of the target city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The city with the given id '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'connect',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Connects two cities with the given border and updates adjacncy list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'idx1'
                        }
                      ],
                      doc => [
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'idx2'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'border'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'idx1',
                type => 'const size_t &'
              },
              {
                declaration_name => 'idx2',
                type => 'const size_t &'
              },
              {
                declaration_name => 'border',
                type => 'const BorderType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'findCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Works as the [] overload for out of scope but gives the ID of the found city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1ae1d96a7ee2becdc089361ea6d1403960',
                      content => 'operator[](const string target)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'name of the desired city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t the Id of the city with \'name\' '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Works as the [] overload for out of scope. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1ae1d96a7ee2becdc089361ea6d1403960',
                      content => 'operator[](const string target)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'name of the desired city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The desired city obj '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the desiured city by id (works like [] overload) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1acc63b666965ca2606df11b94121aadfa',
                      content => 'operator[](const size_t id)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'id'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCountry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the country of that name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of the country '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'Country* The country of that name '
                    }
                  ]
                }
              ]
            },
            type => 'Country *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCapital',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the capital of that country. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'country'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of the country with the desired capital '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The capital of the city (where influence is places) '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'country',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'checkConnection',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks to see if there is a connection between the two named cities. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'A'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Starting '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'B'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Ending '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The cities share a connection '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The cities don\'t share a connection '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'A',
                type => 'const string'
              },
              {
                declaration_name => 'B',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getClosestCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the city closest to the x,y coords from the mouse position. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The x coord of the anchor '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The y coord of the anchor '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'zoom'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The zoom scale to apply when looking at distance '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The city closest to the (x,y) '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'zoom_x',
                type => 'const double'
              },
              {
                declaration_name => 'zoom_y',
                type => 'const double'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNumCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the total number of cities. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const size_t The total number of cities (shouldn\'t change after initalization) '
                    }
                  ]
                }
              ]
            },
            type => 'const size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCities',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get reference to hash map of cities to reduce calls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const unordered_map<string, City*>& The city hashmap reference '
                    }
                  ]
                }
              ]
            },
            type => 'const unordered_map< string, City * > &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCountries',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get reference to hash map of countries to reduce calls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const unordered_map<string, Country*>& The city hashmap reference '
                    }
                  ]
                }
              ]
            },
            type => 'const unordered_map< string, Country * > &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getAdjacency',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the adjacency matrix of cities to reduce calls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const vector<vector<BorderType>>& The adjacency matrix reference '
                    }
                  ]
                }
              ]
            },
            type => 'const vector< vector< BorderType > > &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints all the cities and stats (not connections) '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Evokes each city to free memory before clearing the hasmap and masterlist. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'list_size',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The size or amount of cities in the game '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'countries',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hash table of all countrues where the country is a collection of cities that share the same influence '
                }
              ]
            },
            type => 'unordered_map< string, Country * >'
          },
          {
            kind => 'variable',
            name => 'cities',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hash table of all cities where the city pointer is the value of the '
                },
                {
                  type => 'url',
                  link => 'struct_city',
                  content => 'City'
                },
                {
                  type => 'text',
                  content => ' key name '
                }
              ]
            },
            type => 'unordered_map< string, City * >'
          },
          {
            kind => 'variable',
            name => 'city_masterlist',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Masterlist of all cities '
                }
              ]
            },
            type => 'vector< City * >'
          },
          {
            kind => 'variable',
            name => 'adjacency',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< Is an adjacency matrix of the cities where the connection of cities is reresented by as nonzero value (0 is an offset city) '
                }
              ]
            },
            type => 'vector< vector< BorderType > >'
          },
          {
            kind => 'variable',
            name => 'sortedX',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Sorts all cities by their x value (left...right) '
                }
              ]
            },
            type => 'vector< City * >'
          },
          {
            kind => 'variable',
            name => 'sortedY',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Sorts all cities by their y value (bottom...top) '
                }
              ]
            },
            type => 'vector< City * >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'PeaceChit',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'PeaceChit'
        },
        {
          name => 'x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'PeaceChit'
        },
        {
          name => 'y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'PeaceChit'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Player',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Player.h'
      },
      all_members => [
        {
          name => 'achieved_tech',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'action_card_start',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'action_hand',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'add',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'allegiance',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'allegiance_viewing',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'app',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'atomic',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'atWar',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'axis_dow',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'axisInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'battles_lost',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'battles_won',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'board_change',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'bought_action',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'bought_invest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'calculateProduction',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'capital',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'card_size',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'cards_spent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'cities_controlled',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'city_viewing',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'closest_map_city',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'controlled_cities',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'current_production',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'cursor_x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'cursor_y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'deal',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'deal',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'displayed_cities',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'factory_cost',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getActionCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getActionSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getAllegiance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getAxisDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getCapital',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getControlledCitiesBegin',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getControlledCitiesEnd',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getControlledSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getCurrentProduction',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getHandSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getIndustry',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getIndustryCost',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getInvestCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getInvestSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getMaxCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getMaxProduction',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getNumBlockaded',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getPeaceDividend',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getPeaceDividendSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getPopulation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getResource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getTech',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getTechSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getUsaDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getUssrDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getVP',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getWestDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getYearAtPeace',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'givePeaceDividend',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'industry',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'invest_card_start',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'invest_hand',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'isEnemy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'map_sprite',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'max_production',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'peace_dividends',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'population',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'production_actions',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'resources',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'rival_capitals',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'selected_unit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setAxisDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setPopulation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setResource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setUsaDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setUssrDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setWestDow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'show_action',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'show_invest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'sprite_sheet',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'tech_card_start',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'total_units',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'unit_counts',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'unit_viewing',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'units',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'units_sprite_z1',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'units_sprite_z3',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'usa_dow',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'ussr_dow',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'ussrInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'victory_points',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'west_dow',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'westInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'year_at_peace',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'zoom',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a blank default '
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Constructs the player based on the allegiance. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of player '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Which power they\'ll play '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Constructs a new player. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of player '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Which power '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'population'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Starting population (pop) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resource'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Starting resources (red) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'industry'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Starting industry (ind) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'card_size'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Starting max hand size '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'factory_cost'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Starting cost to upgrade industry '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'ussr_dow'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Inital ties with USSR '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'axis_dow'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Inital ties with AXIS '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'allies_dow'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Inital ties with WEST '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'usa_dow'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Inital USA involvement '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              },
              {
                declaration_name => 'population',
                type => 'const size_t'
              },
              {
                declaration_name => 'resource',
                type => 'const size_t'
              },
              {
                declaration_name => 'industry',
                type => 'const size_t'
              },
              {
                declaration_name => 'card_size',
                type => 'const size_t'
              },
              {
                declaration_name => 'factory_cost',
                type => 'const size_t'
              },
              {
                declaration_name => 'ussr_treaty',
                type => 'const DowState'
              },
              {
                declaration_name => 'axis_treaty',
                type => 'DowState'
              },
              {
                declaration_name => 'allies_treaty',
                type => 'DowState'
              },
              {
                declaration_name => 'usa_treaty',
                type => 'const DowState'
              },
              {
                declaration_name => 'capital',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'westInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup West player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'axisInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup Axis player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ussrInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup USSR player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'add',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a city to the current control list of the player. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The city to be controlled by the player '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getControlledCitiesBegin',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the begin iterator of the controlled cities hashmap to iteratre through. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'unordered_map<string,City*>::const_iterator '
                    }
                  ]
                }
              ]
            },
            type => 'unordered_map< string, City * >::const_iterator',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getControlledCitiesEnd',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the end iterator of the controlled cities hashmap to iteratre through. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'unordered_map<string,City*>::const_iterator '
                    }
                  ]
                }
              ]
            },
            type => 'unordered_map< string, City * >::const_iterator',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getControlledSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of controlled cities. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t Number of controlled cities '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getNumBlockaded',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of cities controlled that are blockaded. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t Number of blockaded cities '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'isEnemy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'See if the player allegiance provided is an enemy of the player (has a DOW) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance to check if an enemy '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Is an enemy '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Is not an enemy (at peace) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'const CityType &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'deal',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gives the player the provided card into the corresponding hand. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'aC'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The action card to add into the action hand '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'aC',
                type => 'ActionCard *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'deal',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gives the player the provided card into the corresponding hand. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'iC'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The invest card to add into the action hand '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'iC',
                type => 'InvestmentCard *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getAllegiance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets which power the player is. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'CityType The Power the player is '
                    }
                  ]
                }
              ]
            },
            type => 'CityType',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getPopulation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get how much population the player controls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The player\'s population '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getActionSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of action cards the player has. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t number of action cards '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getInvestSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of invest cards the player has. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t number of invest cards '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getTechSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of achieved tech the player has. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t number of achieved tech '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getResource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of resources owned. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t Number of resources '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getIndustry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the current industry (ind) of the player. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The current industry of player '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getIndustryCost',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the cost to add 1 to the current industry. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t the cost of upgrading industry '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setPopulation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the players population. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'pop'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new population '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'pop',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setResource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the number of resources. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'res'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new resource count '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'res',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHandSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the combined hand size of action and investment cards. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getUssrDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the USSR Declaration of War. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'DowState The state of the DOW (peacful, victim, or declarer) '
                    }
                  ]
                }
              ]
            },
            type => 'DowState',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getWestDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the WEST Declaration of War. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'DowState The state of the DOW (peacful, victim, or declarer) '
                    }
                  ]
                }
              ]
            },
            type => 'DowState',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getAxisDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the AXIS Declaration of War. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'DowState The state of the DOW (peacful, victim, or declarer) '
                    }
                  ]
                }
              ]
            },
            type => 'DowState',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getUsaDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the USA Declaration of War which represents the. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'DowState The state of the DOW (peacful, victim, or declarer) '
                    }
                  ]
                }
              ]
            },
            type => 'DowState',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getYearAtPeace',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the last year the player was peaceful. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t the year at peace '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCapital',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the capital of the player that the traderoutes need to be traced to. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'string Name of the capital '
                    }
                  ]
                }
              ]
            },
            type => 'string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setUssrDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the USSR DoW state. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ds'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new state of the USSR DoW '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ds',
                type => 'const DowState'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setWestDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the WEST DoW state. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ds'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new state of the USSR DoW '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ds',
                type => 'const DowState'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setAxisDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the AXIS DoW state. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ds'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new state of the USSR DoW '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ds',
                type => 'const DowState'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setUsaDow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the USA DoW state. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ds'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new state of the USSR DoW '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ds',
                type => 'const DowState'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMaxCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'gets the player\'s card limit '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The card limit '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getActionCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the Action Card at the specific index. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'indx'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The index of the wanted card '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'ActionCard* The pointer of the desired card '
                    }
                  ]
                }
              ]
            },
            type => 'ActionCard *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'indx',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getInvestCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the Invest Card at the specific index. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'indx'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The index of the wanted card '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'InvestmentCard* The pointer of the desired card '
                    }
                  ]
                }
              ]
            },
            type => 'InvestmentCard *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'indx',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getTech',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the acheived tech at the specific index. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'indx'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'the desired index of the tech '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const '
                    },
                    {
                      type => 'url',
                      link => 'struct_technology',
                      content => 'Technology'
                    },
                    {
                      type => 'text',
                      content => '& The tech at the index '
                    }
                  ]
                }
              ]
            },
            type => 'const Technology &',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'indx',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'calculateProduction',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the min production of the player min(pop, res, ind). If not at war then dont look at res. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The production of the player for the phase '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCurrentProduction',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the Current production of the player for this production phase. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const size_t The current production (or how much they have left to spend) '
                    }
                  ]
                }
              ]
            },
            type => 'const size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMaxProduction',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the max production of the player for this production phase (is calculated in ) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => 'class_player_1aada43d4dfb6f6ead21fe340215e5f150',
                      content => 'calculateProduction'
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const size_t The max production of the player for this production phase '
                    }
                  ]
                }
              ]
            },
            type => 'const size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'atWar',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets if the player is at war with any other player. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Is at war with another player '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Is not at war (not neccisarily peaceful if the VoN) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getVP',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the current VP of player. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The victory points of the player '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'givePeaceDividend',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gives the player a peace chit. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'chit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The chit to give the player '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'chit',
                type => 'const PeaceChit'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getPeaceDividend',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the peace chit at the specific index. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'i'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The index of the peace chit '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'url',
                      link => 'struct_peace_chit',
                      content => 'PeaceChit'
                    },
                    {
                      type => 'text',
                      content => '& Refrence to the peace chit '
                    }
                  ]
                }
              ]
            },
            type => 'PeaceChit &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'i',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getPeaceDividendSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of peace chits owned. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The number of peace chits '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints out all stats of the player. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Frees the memort allocated for the player. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'production_actions',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'stack< ProductionAction >'
          },
          {
            kind => 'variable',
            name => 'unit_counts',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An array of the count of how many units on the board this player has made '
                }
              ]
            },
            type => 'int',
            arguments => '[7]',
            initializer => '= {0, 0, 0, 0, 0, 0, 0}'
          },
          {
            kind => 'variable',
            name => 'app',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Container for the attributes of the player\'s window/screen and renderer '
                }
              ]
            },
            type => 'App *'
          },
          {
            kind => 'variable',
            name => 'sprite_sheet',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The general spritesheet for the player\'s renderer '
                }
              ]
            },
            type => 'Spritesheet *'
          },
          {
            kind => 'variable',
            name => 'map_sprite',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The spirte of the map for the player\'s renderer '
                }
              ]
            },
            type => 'Spritesheet *'
          },
          {
            kind => 'variable',
            name => 'units_sprite_z1',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite sheet for units at zoom 1 (the broadest) '
                }
              ]
            },
            type => 'Spritesheet *'
          },
          {
            kind => 'variable',
            name => 'units_sprite_z3',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The sprite sheet for the units at zoom 3 (the closest) '
                }
              ]
            },
            type => 'Spritesheet *'
          },
          {
            kind => 'variable',
            name => 'action_card_start',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which action card to start displaying on the main home screen '
                }
              ]
            },
            type => 'int',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'invest_card_start',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which invest card to start displaying on the main home screen '
                }
              ]
            },
            type => 'int',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'tech_card_start',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which discovered tech card to start displaying on the main home screen '
                }
              ]
            },
            type => 'int',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'zoom',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current zoom level (1,2,3) of the player\'s screen '
                },
                {
                  type => 'linebreak'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'int',
            initializer => '= 1'
          },
          {
            kind => 'variable',
            name => 'bought_action',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current number of action cards the player intends to buy '
                }
              ]
            },
            type => 'size_t',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'bought_invest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current number of invest cards the player intends to buy '
                }
              ]
            },
            type => 'size_t',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'board_change',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Boolen to track wether the player\'s board/view has changed and needs to be redrawn '
                }
              ]
            },
            type => 'bool',
            initializer => '=true'
          },
          {
            kind => 'variable',
            name => 'show_action',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Boolean to track if the action hand should be expanded to show all cards '
                }
              ]
            },
            type => 'bool',
            initializer => '= false'
          },
          {
            kind => 'variable',
            name => 'show_invest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Boolean to track if the invest hand should be expanded to show all cards '
                }
              ]
            },
            type => 'bool',
            initializer => '= false'
          },
          {
            kind => 'variable',
            name => 'cursor_x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current x coord of the player\'s cursor on the screen '
                }
              ]
            },
            type => 'double',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'cursor_y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current y coord of the player\'s cursor on the screen '
                }
              ]
            },
            type => 'double',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'city_viewing',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The ID of the city being view or in focus, meaning all action are set to this '
                }
              ]
            },
            type => 'int',
            initializer => '= -1'
          },
          {
            kind => 'variable',
            name => 'unit_viewing',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The ID of the unit being view or in focus, meaning all action are set to this '
                }
              ]
            },
            type => 'int',
            initializer => '= -1'
          },
          {
            kind => 'variable',
            name => 'allegiance_viewing',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The allegiance of the unit being view or in focus '
                }
              ]
            },
            type => 'CityType',
            initializer => '= NEUTRAL'
          },
          {
            kind => 'variable',
            name => 'selected_unit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The unit thats under focus and all actions pertaining to '
                }
              ]
            },
            type => 'Unit *',
            initializer => '= nullptr'
          },
          {
            kind => 'variable',
            name => 'closest_map_city',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The city that is closest to the player\'s cursor (updated when cursor stops moving) '
                }
              ]
            },
            type => 'City *',
            initializer => '= nullptr'
          },
          {
            kind => 'variable',
            name => 'displayed_cities',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Vector of all cities pinned by the player to show all information '
                }
              ]
            },
            type => 'vector< City * >'
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The name of the player '
                }
              ]
            },
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'victory_points',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Current number of VP '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'rival_capitals',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Number of enemy capitals the player has captured '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'atomic',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the player has all 4 stages of atomics '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          },
          {
            kind => 'variable',
            name => 'year_at_peace',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Is the last year the player was at peace (used for peace chits) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'allegiance',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which power the player is controlling (West, Axis, USSR) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'population',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Total POP of the player '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resources',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Total number of resources player has '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'industry',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Total number of industry the player has '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'card_size',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hand size of the player they must discard to at the end of government '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'factory_cost',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The cost to upgrade the industry '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'max_production',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Max production level of the player for the current production phase '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'current_production',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current production left for the pleyer for the production phase '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'units',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Masterlist of all units the player controls '
                }
              ]
            },
            type => 'vector< Unit * >'
          },
          {
            kind => 'variable',
            name => 'achieved_tech',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'List of all technologies that the player has discovered '
                }
              ]
            },
            type => 'vector< Technology >'
          },
          {
            kind => 'variable',
            name => 'controlled_cities',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Masterlist of all cites the player controls '
                }
              ]
            },
            type => 'unordered_map< string, City * >'
          },
          {
            kind => 'variable',
            name => 'ussr_dow',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds the diplomacy state of the DOW with USSR '
                }
              ]
            },
            type => 'DowState',
            initializer => '=PEACE'
          },
          {
            kind => 'variable',
            name => 'west_dow',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds the diplomacy state of the DOW with USSR '
                }
              ]
            },
            type => 'DowState',
            initializer => '=PEACE'
          },
          {
            kind => 'variable',
            name => 'axis_dow',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds the diplomacy state of the DOW with USSR '
                }
              ]
            },
            type => 'DowState',
            initializer => '=PEACE'
          },
          {
            kind => 'variable',
            name => 'usa_dow',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds the diplomacy state of the DOW with USA (only for the WEST really) '
                }
              ]
            },
            type => 'DowState',
            initializer => '=PEACE'
          },
          {
            kind => 'variable',
            name => 'capital',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The capital city of the player (either London, Berlin, or Moscow) '
                }
              ]
            },
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'action_hand',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hand of all action cards (used in command and government) '
                }
              ]
            },
            type => 'vector< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_hand',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hand of all investment cards '
                }
              ]
            },
            type => 'vector< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'peace_dividends',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'List of all peace chits earned '
                }
              ]
            },
            type => 'vector< PeaceChit >'
          },
          {
            kind => 'variable',
            name => 'battles_won',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Allies:0 Axis:1 USSR:2 where each index specifies against who '
                }
              ]
            },
            type => 'size_t',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'battles_lost',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A llies:0 Axis:1 USSR:2 where each index specifies against who '
                }
              ]
            },
            type => 'size_t',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'total_units',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Each index is a specific unit and how much '
                }
              ]
            },
            type => 'size_t',
            arguments => '[8]'
          },
          {
            kind => 'variable',
            name => 'cards_spent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Number of cards the player has spent this game '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'cities_controlled',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Number of cities the player controls '
                }
              ]
            },
            type => 'size_t'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Represents Great Power and '
          },
          {
            type => 'url',
            link => 'class_player',
            content => 'Player'
          },
          {
            type => 'text',
            content => ' Stats. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Runner',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Runner.h'
      },
      all_members => [
        {
          name => 'action_deck',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'action_discard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'app',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'axis_controller',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'blockade',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'canBuild',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'canDisengage',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'canMove',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'canUpgrade',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'checkTradeRoutes',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'ClearScreen',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'combatRound',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'controllers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'current_player',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'deal',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'decideTurnOrder',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'die',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'disengage',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'drawActionCards',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawCity',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawCity',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawCityUnits',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawConnections',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawFullCityUnits',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawInfluence',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawInvestCards',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawMap',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawMemoResolution',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawMemoResolution',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawNumber',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawPeaceDividends',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawPlayerBoard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawProductionPhase',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'drawTurnRoll',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawUnit',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'end_year',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'fall',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'g',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'getBattles',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'getCitySprite',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'getMap',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'getNumPlayers',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'government',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'handCheck',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'handleButtonDown',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'handleJoyStickMovement',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'handleTriggerMovement',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'handleUserInput',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'inBox',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'InitApplication',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'initCards',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'initMap',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'InitSDL',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'invest_deck',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'invest_discard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'isSupllied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'landCombat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'last_tick',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'map',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'map_changed',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'map_sprite',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'mapPlayer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'move',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'newYear',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'newYearRes',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'num_players',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'pastDeadZone',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'peace_dividends_bag',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'peaceDividends',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'players',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'powers_app',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'powers_map_sprite',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'powers_sprite_map',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'powers_units_sprite_z1',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'powers_units_sprite_z3',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'printMemo',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'production',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'reshuffle',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'reshuffleAnimation',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'run',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'Runner',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'scaleAxis',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'seaCombat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'season',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'seed',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'setResXY',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'setXY',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'ShutdownApplication',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'spring',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'sprite_map',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'start_player',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'summer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'test',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'turn_order',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'ussr_controller',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'west_controller',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'winter',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'year',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Runner',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'class_runner',
                  content => 'Runner'
                },
                {
                  type => 'text',
                  content => ' object that intializes the map and players. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'default_mode'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'true if should go off of default or read in through the map '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'default_mode',
                type => 'bool',
                default_value => 'true'
              }
            ]
          },
          {
            kind => 'function',
            name => 'test',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'initMap',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Creates the game map including nations and cities and connections. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Was able to succesfully make the map '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Encountered an error while making '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'map_file',
                type => 'string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'initCards',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Creates the decks of cards. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'invest_file',
                type => 'const string'
              },
              {
                declaration_name => 'action_file',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'run',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The main runner of the game loop. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The game is over with a winner '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The game is still going on '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'newYear',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The first phase of the game loop where vicotry is checked, cards reshuffled, peace chits are distributed, USA influence, production, govenment phase occur. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => 'class_runner_1a38409a814f07a34df8461ae4d33b2af1',
                      content => 'peaceDividends()'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => 'class_runner_1ad62bb8027061f8fbd5eced9182ff8db1',
                      content => 'reshuffle()'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => 'class_runner_1a805a1522e9541c31df3a136d58f99ec2',
                      content => 'newYearRes()'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => 'class_runner_1a1d0e5459a22a49dbf34b0d75f6383676',
                      content => 'production()'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => 'class_runner_1a024ca94b6ff3d8213d236d87c0c6abb5',
                      content => 'government()'
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'CityType The player who won the game (CityType::Water if there is no winner) '
                    }
                  ]
                }
              ]
            },
            type => 'CityType',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'reshuffle',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'New Year phase where Cards in the discard piles will be added to both draw decks and then the whole deck will be reshuffled. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'animation'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Bool which will play the reshuffle animation if true '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'animation',
                type => 'const bool'
              }
            ]
          },
          {
            kind => 'function',
            name => 'peaceDividends',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'All players who have been peacful (not DoW\'s or VoN in the past year) will recieve a random chit of 0, 1, or 2 VP\'s. This happens in the first year as well. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'decideTurnOrder',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'New Year phase where the turn order of the players is decided for the following year. A D6 is rolled and depending on the number the strting player, and rotation is decided. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'animation',
                type => 'const bool',
                default_value => 'false'
              }
            ]
          },
          {
            kind => 'function',
            name => 'newYearRes',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'In specific years 1 WEST influence will be added to the USA and if the USA is already a satellite then one of each unit will be automattically added to Washington and New York. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'production',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'New Year phase where players can spend there production (lowest of pop/res/ind) on buying cards, building cadres, and upgrading units. Runs on the turn order until all have gone through. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'drawProductionPhase',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles what to draw during the production phase. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'deal',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Deal a set amount of cards to the player of action or invest. Hand limit doesn\'t apply to card drawing. The player will draw up onto the amount or the number of cards remaining in the deck. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player recieveing the cards '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'amount'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The amount of the card the player will recieve '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'state'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The type of card to deal \'A\': action, \'I\': invest '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The player was able to draw all cards '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The player wasn\'t able to draw all cards '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player *'
              },
              {
                declaration_name => 'amount',
                type => 'size_t'
              },
              {
                declaration_name => 'state',
                type => 'const char',
                default_value => '\'A\''
              }
            ]
          },
          {
            kind => 'function',
            name => 'government',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'New Year phase where players play action cards to add influence and play investment cards, goes in turn order until all have passed. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'handCheck',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks the players hand to see if it is over the card limit, and to discard down to the hand limit. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose hand will be checked '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'spring',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Spring season of war where players will commence the war. Action cards with spring will have priority. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'summer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Summer season of war where players will commence the war and after which blockades will be added. Action cards with SUMMER will have priority. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'blockade',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'At the end of summer, cities who cannot trace a trade route to the Main Capital of its ruler is blockaded and the pop/res won\'t be counted in production. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'fall',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Fall season of war where players will commence the war. Action cards with FALL will have priority. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'winter',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The winter season of war where the USSR player can act inside of the bounds of the USSR. Only the USSR player can act during this turn. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'mapPlayer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Goes over the players holdings over the map and sums up their pop, res, CV. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose cities will be checked '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true No changes were made from the stored attributes '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Changes were made from stale attributes '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'checkTradeRoutes',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'During the production phase it needs to verify all cities controlled by the player that are blockaded are still blockaded (route can only include 1 land segment and 1 sea segment) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose trade routes are being checked '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'main_capital'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The capital of the player that the cities must conenct to '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Blockades were removed '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Blockades weren\'t removed '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              },
              {
                declaration_name => 'main_capital',
                type => 'const string &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'isSupllied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A decider for if the city provided is supplied and can have steps built. All the cities on the route are marked as supplied to decrease redundancy. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player who would build the unit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city where the unit wants to be built '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The allegiance of the current city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The city is suplliable '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The city is not suplliable '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'canBuild',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Decider for if a new unit of the given type is able to be built in the city provided. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'class_player',
                          content => 'Player'
                        },
                        {
                          type => 'text',
                          content => ' whose troop will be added '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city where the unit wants to be added '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'nationality'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The nationality (or color) of the unit that wants to be added (used to track limits) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The type of unit that wants to be added (used to track limits) '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'ProductionError The error given as to why it can\'t be built (0 if no error) '
                    }
                  ]
                }
              ]
            },
            type => 'ProductionError',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              },
              {
                declaration_name => 'nationality',
                type => 'const UnitCountry'
              },
              {
                declaration_name => 'unit',
                type => 'const UnitType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'canUpgrade',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Decider for if an exisiting unit can be upgraded. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player who wants to upgrade the unit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city where the unit is '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'nationality'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The nationality of the unit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The unit who would be upgraded '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'ProductionError The error given as to why it can\'t be upgrade (0 if no error) '
                    }
                  ]
                }
              ]
            },
            type => 'ProductionError',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              },
              {
                declaration_name => 'nationality',
                type => 'const UnitCountry'
              },
              {
                declaration_name => 'unit',
                type => 'const Unit *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'move',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks what type of movement is allowed and if the player is allowed to move there. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit being moved '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The Starting city being left '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'end'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The destination of the unit '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The unit was able to move '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The unit was unable to move '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'canDisengage',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks if the player can disengage from the current battle. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Logic Checks.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'class_unit',
                          content => 'Unit'
                        },
                        {
                          type => 'text',
                          content => ' disengaging '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city with the battle being fled from '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'end'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The potential city to flee to '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Able to disengage '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Unable to disengage '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'disengage',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When the unit is leaving a battle it can move to one adjacent friendly city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit disengaging '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city with the conflict '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'end'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city to disengage to '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Is able to move to end '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false is unable (border limits or out of range or not friendly) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'canMove',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks if that unit is able to move into that city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit moving '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The target '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t How much movement would be left (returns INFI if it can\'t) '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'combatRound',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes the current players combat rounds. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'landCombat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes a land battle at the given city for one combat round. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'battlefield'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The city with the battle taken place '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'battlefield',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'seaCombat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes a sea battle at the given \'city\' until concluded. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'battlefield'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The \'city\' with the battle taken place '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true if the combat round needs to repeat '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false if the battle fininshed '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'battlefield',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getBattles',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Check which cities have a current battle happening. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the current player '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'vector<City*> Vector of all cities the player is batteling for '
                    }
                  ]
                }
              ]
            },
            type => 'vector< City * >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNumPlayers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of players. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The number of playes in the game (2 or 3) '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMap',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the map of the game. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const '
                    },
                    {
                      type => 'url',
                      link => 'class_map',
                      content => 'Map'
                    },
                    {
                      type => 'text',
                      content => '& A const reference to the game map and cities '
                    }
                  ]
                }
              ]
            },
            type => 'const Map &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Free the allocated memory of the whole game. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'printMemo',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'memo',
                type => 'size_t',
                array => '[][5]'
              }
            ]
          },
          {
            kind => 'function',
            name => 'InitSDL',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes SDL2 and the window. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Initalized succesfully '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Failexcd to initalize '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'InitApplication',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes the \'app\', the struct that hlds the renderer and the window. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Initalized succesfully '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Failexcd to initalize '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ShutdownApplication',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Deletes the windows and frees memory specifically used by SDL. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ClearScreen',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Clears the screen so the screen can \'update\'. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'renderer',
                type => 'SDL_Renderer *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawMap',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw\'s the map to the main rendered with different options to control what is shown. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'cities'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Draws all cities if true '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'influence'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Draws the influence markers on each applicable city if true '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resources'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Draw the resources of each city if true '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'connections'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Draw the line connections (colored by type) between connected cities if true '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'render'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Will render the map onto the renderer if true (used for when nothing will be added ontop of the map) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'fps'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'If a fps is provided it will draw it onto the renderer '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'cities',
                type => 'const bool'
              },
              {
                declaration_name => 'influence',
                type => 'const bool'
              },
              {
                declaration_name => 'resources',
                type => 'const bool'
              },
              {
                declaration_name => 'connections',
                type => 'const bool'
              },
              {
                declaration_name => 'render',
                type => 'const bool',
                default_value => 'true'
              },
              {
                declaration_name => 'fps',
                type => 'const int &',
                default_value => '-1'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawPlayerBoard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the private view of the player including cards and VP and production levels and acheived tech. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '!! Drawing '
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' board'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose card is being drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'renderer'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The player\'s renderer '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'renderer',
                type => 'SDL_Renderer *'
              },
              {
                declaration_name => 'bought_action',
                type => 'const int',
                default_value => '0'
              },
              {
                declaration_name => 'bought_invest',
                type => 'const int',
                default_value => '0'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCitySprite',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the index of the sprite needed for the city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The city being drawn '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'int The index of the sprite in the sprite map '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawCity',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a city onto the players renderer and if opted the resources as well. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose screen will have the city drawn on '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city being drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resources'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'If the resources should be drawn or not '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              },
              {
                declaration_name => 'resources',
                type => 'const bool',
                default_value => 'true'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawCity',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw a city marker (not tied to any specific city) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The x-coord of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The y-coord of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'population_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The type of city to draw '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'int'
              },
              {
                declaration_name => 'y',
                type => 'int'
              },
              {
                declaration_name => 'population_type',
                type => 'PopulationType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawUnit',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the unit onto the player\'s screen. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose screen will have the unit drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The unit that will be drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x-coord of the unit to draw '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The y-coord of the unit to draw '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'zoom'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The zoom level of the player\'s map to determine units level of detail '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'secret'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'If true the unit sprite will be a question mark only showing the nationality (for when not in combat and not the player\'s allegiance)'
                        }
                      ]
                    }
                  ]
                },
                {
                  pre => [
                    {
                      type => 'text',
                      content => 'x and y have already been scaled '
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'unit',
                type => 'const Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'zoom',
                type => 'const int'
              },
              {
                declaration_name => 'secret',
                type => 'const bool',
                default_value => 'false'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawCityUnits',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws 5 units under the city, rotating to the next 5 every 5 seconds. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose screen will have the units drawn (also affects which units are visible) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city whose occupants will be drawn '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawFullCityUnits',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the city has full displayed enable, every unit at the city will be displayed in rows of 5 (no rotation) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player who opted for the city to be fully displayed '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city whose units will all be shown '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawInfluence',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the influence tokens onto the map. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose screen will have the tokens rendered to '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawActionCards',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the players action cards onto their screen starting at the given x and y and decends. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player\'s cards to draw '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start_x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The top right x-coord corner of where cards should be drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start_y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The top right y-coord corner of where cards should be drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'count'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The amount of cards to be drawn (max amount drawn will be XX) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'THe scale of the cards to draw '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player *'
              },
              {
                declaration_name => 'start_x',
                type => 'int'
              },
              {
                declaration_name => 'start_y',
                type => 'int'
              },
              {
                declaration_name => 'count',
                type => 'int'
              },
              {
                declaration_name => 'scale',
                type => 'int',
                default_value => '1'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawInvestCards',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the players invest cards onto their screen starting at the given x and y and decends. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player\'s action cards to draw '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start_x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The top right x-coord corner of where cards should be drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start_y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The top right y-coord corner of where cards should be drawn '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'count'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The amount of cards to be drawn (max amount drawn will be XX) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'THe scale of the cards to draw '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player *'
              },
              {
                declaration_name => 'start_x',
                type => 'int'
              },
              {
                declaration_name => 'start_y',
                type => 'int'
              },
              {
                declaration_name => 'count',
                type => 'int'
              },
              {
                declaration_name => 'scale',
                type => 'int',
                default_value => '1'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawConnections',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws all the connections between the cities and colors them based on the type of border. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'The'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'player whose screen will have connections drawn on '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawNumber',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Takes any length number and draws it as a 7-segment at the x,y as the top left. Origional scale is 7*13 for one digit. Default color is black. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'renderer'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The rendererer to draw the number onto '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'num'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Number to render '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'X coord of number origin '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Y coord of number origin '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Scales draw size of the number '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'r'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The red value of the color (0, 255) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'g'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The green value of the color (0, 255) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'b'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The blue value of the color (0, 255) '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'renderer',
                type => 'SDL_Renderer *'
              },
              {
                declaration_name => 'num',
                type => 'int'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              },
              {
                declaration_name => 'r',
                type => 'const uint8_t',
                default_value => '255'
              },
              {
                declaration_name => 'g',
                type => 'const uint8_t',
                default_value => '255'
              },
              {
                declaration_name => 'b',
                type => 'const uint8_t',
                default_value => '255'
              }
            ]
          },
          {
            kind => 'function',
            name => 'reshuffleAnimation',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Animation of the cards from the discard pile being added back. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'action_size'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Number of action cards to add back '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'invest_size'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Number of invest cards to add back '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'action_size',
                type => 'const size_t &'
              },
              {
                declaration_name => 'invest_size',
                type => 'const size_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawMemoResolution',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Takes the memo of the Dijkstra\'s knock-off II for finding trade routes and highlighting the route it takes. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'memo'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The completed memo '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'unblocked'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The list of cities who were unblockaded and there path will be shown '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'memo',
                type => 'const vector< std::array< size_t, 6 > > &'
              },
              {
                declaration_name => 'unblocked',
                type => 'vector< City * >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawMemoResolution',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the memo of the Dijkstra\'s knock-off III for supply routes. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose screen it will be drawn too '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'memo'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The completed memo of the algorithm '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'const Player &'
              },
              {
                declaration_name => 'memo',
                type => 'const vector< std::array< size_t, 4 > > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawTurnRoll',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Animation for rolling a D6 and form that the turn order that is decided. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'result'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The result of the dice roll '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'result',
                type => 'const int &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawPeaceDividends',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Animation of the cities who were peacful receiving a peace chit. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'west'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Bool if the WEST player should be shown receiving a peace chit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'axis'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Bool if the AXIS player should be shown receiving a peace chit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'ussr'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Bool if the USSR player should be shown receiving a peace chit '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'west',
                type => 'const bool'
              },
              {
                declaration_name => 'axis',
                type => 'const bool'
              },
              {
                declaration_name => 'ussr',
                type => 'const bool'
              }
            ]
          },
          {
            kind => 'function',
            name => 'inBox',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Used for button presses where a given mouse clip position will see if its in the rectangle provided. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The top left x-coord of the rectangle '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The top left y-coord of the rectangle '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'width'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The width of the button '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'height'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The height of the button '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'target_x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x-coord where the mouse clicked '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'target_y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The y-coord where the mouse clicked '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The click is in the button '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The click is not in the button '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'width',
                type => 'const int'
              },
              {
                declaration_name => 'height',
                type => 'const int'
              },
              {
                declaration_name => 'target_x',
                type => 'const int'
              },
              {
                declaration_name => 'target_y',
                type => 'const int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleUserInput',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Main handler for all possible user input. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'running'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Reference to the check if the game loop should continue running and can be changed if player inputs it so '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'running',
                type => 'bool &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleButtonDown',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handels the cases where the player pressed down on a button. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player who commenced the event '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The button down event by the player '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              },
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleJoyStickMovement',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handels the players controller joystick movement the dictates cursor movement and is called only every frame to make game smoother. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose controller is checked for movement '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleTriggerMovement',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handels the players controller trigger (L2, R2) movement that dictates zoom and is called only every frame to make game smoother. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The player whose controller is checked for movement '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setXY',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Dev tool for setup when deciding the X and Y of the city, it\'ll print which city and then record the clicked X and Y as the location of the city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'path'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'path',
                type => 'const string &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setResXY',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Dev tool to Set the resource x and y coords for each city that has a resource. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'pastDeadZone',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks if the joy stick movement is within the accepted range of movement (fights stick drift) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'move'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The degree of the joystick movement '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The movement is acceptable '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The movement is unacceptable (in the dead zone) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'move',
                type => 'const int &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'scaleAxis',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Takes a joy axis movement and scales it to be from [0.0, 1.0] bases on a min movement of -32000 and max movement of 32000. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The joy axis movement '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'double The scaled joy axis movement '
                    }
                  ]
                }
              ]
            },
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'const double &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'num_players',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Number of player in game (3 but hopefully can make a 1) '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'players',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Player',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'map',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds each playe object with allegiance as index 0: West 1: Axis 2: USSR '
                },
                {
                  type => 'url',
                  link => 'class_map',
                  content => 'Map'
                },
                {
                  type => 'text',
                  content => ' of the game and nations/waters '
                }
              ]
            },
            type => 'Map'
          },
          {
            kind => 'variable',
            name => 'year',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Current year the player is in (goes from 1936 to 1945) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'end_year',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Year the game will end (usually 1945) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'season',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current season being playes '
                }
              ]
            },
            type => 'Season',
            initializer => '=NEW_YEAR'
          },
          {
            kind => 'variable',
            name => 'die',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'url',
                  link => 'struct_dice',
                  content => 'Dice'
                },
                {
                  type => 'text',
                  content => ' used to roll decisions, default a D6 '
                }
              ]
            },
            type => 'Dice'
          },
          {
            kind => 'variable',
            name => 'action_deck',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the action cards '
                }
              ]
            },
            type => 'vector< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'action_discard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the action cards '
                }
              ]
            },
            type => 'vector< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_deck',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the invest cards '
                }
              ]
            },
            type => 'vector< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_discard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Discard pile of investment cards '
                }
              ]
            },
            type => 'vector< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'peace_dividends_bag',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds all the unpulled peace dividends '
                }
              ]
            },
            type => 'vector< PeaceChit >'
          },
          {
            kind => 'variable',
            name => 'start_player',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' who will start the turn '
                }
              ]
            },
            type => 'Player *'
          },
          {
            kind => 'variable',
            name => 'current_player',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The player\'s who current turn it is '
                }
              ]
            },
            type => 'Player *'
          },
          {
            kind => 'variable',
            name => 'turn_order',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Array with the first player at 0 and the last player in the loop at 2 '
                }
              ]
            },
            type => 'Player *',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'seed',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The set (or time set seed) for all randomness '
                }
              ]
            },
            type => 'const unsigned int',
            initializer => '= 100'
          },
          {
            kind => 'variable',
            name => 'g',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The random generator for shuffling '
                }
              ]
            },
            type => 'std::mt19937'
          },
          {
            kind => 'variable',
            name => 'app',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The stuct that holds all window and renderer for SDL2 and shows the main board '
                }
              ]
            },
            type => 'App'
          },
          {
            kind => 'variable',
            name => 'powers_app',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The app (window, rendered, ect) of each player and their board '
                }
              ]
            },
            type => 'App',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'sprite_map',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '!! Graphics things '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A png that holds every sprite in the game and can be indexed into and a clip pulled from in 32 by 32 pixels '
                }
              ]
            },
            type => 'Spritesheet'
          },
          {
            kind => 'variable',
            name => 'map_sprite',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Spritesheet'
          },
          {
            kind => 'variable',
            name => 'powers_sprite_map',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A png that holds every sprite in the game and can be indexed into and a clip pulled from in for the player\'s seperate renderer '
                }
              ]
            },
            type => 'Spritesheet',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'powers_map_sprite',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An array of the spritesheets initaliazed to the powers renderer that has the map '
                }
              ]
            },
            type => 'Spritesheet',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'powers_units_sprite_z1',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An array of the spritesheets initaliazed to the powers renderer that has the units at the first zoom level '
                }
              ]
            },
            type => 'Spritesheet',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'powers_units_sprite_z3',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An array of the spritesheets initaliazed to the powers renderer that has the units at the third zoom level '
                }
              ]
            },
            type => 'Spritesheet',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'west_controller',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The controller of the West player '
                }
              ]
            },
            type => 'SDL_GameController *',
            initializer => '=nullptr'
          },
          {
            kind => 'variable',
            name => 'axis_controller',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The controller of the Axis player '
                }
              ]
            },
            type => 'SDL_GameController *',
            initializer => '=nullptr'
          },
          {
            kind => 'variable',
            name => 'ussr_controller',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The controller of the USSR player '
                }
              ]
            },
            type => 'SDL_GameController *',
            initializer => '=nullptr'
          },
          {
            kind => 'variable',
            name => 'controllers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Array of the controllers so that the controller.which can be used to index the controller obj '
                }
              ]
            },
            type => 'SDL_GameController *',
            arguments => '[3]',
            initializer => '= {nullptr, nullptr, nullptr}'
          },
          {
            kind => 'variable',
            name => 'map_changed',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Boolean that is true when an update has happened on the main screen and the main screen needs to be re-rendered '
                }
              ]
            },
            type => 'bool',
            initializer => '=true'
          },
          {
            kind => 'variable',
            name => 'last_tick',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Used by animations to see how long has elapsed since the last render '
                }
              ]
            },
            type => 'Uint32'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The main controller of the game and controls sequence of play. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Graphics::Screen',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'getCenterX',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'getCenterY',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'getScaleX',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'getScaleY',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'HEIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'WIDTH',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'zoom_factor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'zoom_x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'zoom_y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'getCenterX',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCenterY',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getScaleX',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getScaleY',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'WIDTH',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            initializer => '= 1512'
          },
          {
            kind => 'variable',
            name => 'HEIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            initializer => '= 946'
          },
          {
            kind => 'variable',
            name => 'zoom_factor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'double',
            initializer => '= 1.0'
          },
          {
            kind => 'variable',
            name => 'zoom_x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'zoom_y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            initializer => '= 0'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Spritesheet',
      kind => 'class',
      inner => [
      ],
      all_members => [
        {
          name => 'clip',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Spritesheet'
        },
        {
          name => 'drawSelectedSprite',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'drawSprite',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'renderer',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Spritesheet'
        },
        {
          name => 'selectSprite',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'Spritesheet',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'Spritesheet',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Spritesheet'
        },
        {
          name => 'spritesheet_image',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Spritesheet'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Spritesheet',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Spritesheet',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'path',
                type => 'char const *'
              },
              {
                declaration_name => 'renderer',
                type => 'SDL_Renderer *'
              },
              {
                declaration_name => 'width',
                type => 'int',
                default_value => '32'
              },
              {
                declaration_name => 'height',
                type => 'int',
                default_value => '32'
              }
            ]
          },
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'selectSprite',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'int'
              },
              {
                declaration_name => 'y',
                type => 'int',
                default_value => '0'
              },
              {
                declaration_name => 'clip_x',
                type => 'int',
                default_value => '-1'
              },
              {
                declaration_name => 'clip_y',
                type => 'int',
                default_value => '-1'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawSelectedSprite',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'position',
                type => 'SDL_Rect *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawSprite',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'position',
                type => 'SDL_Rect *'
              },
              {
                declaration_name => 'row',
                type => 'int'
              },
              {
                declaration_name => 'pos',
                type => 'int'
              },
              {
                declaration_name => 'size_x',
                type => 'int',
                default_value => '32'
              },
              {
                declaration_name => 'size_y',
                type => 'int',
                default_value => '32'
              },
              {
                declaration_name => 'offset',
                type => 'int',
                default_value => '0'
              },
              {
                declaration_name => 'unscaledX',
                type => 'int',
                default_value => '0'
              },
              {
                declaration_name => 'unscaledY',
                type => 'int',
                default_value => '0'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'clip',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Rect'
          },
          {
            kind => 'variable',
            name => 'spritesheet_image',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'renderer',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Renderer *'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Technology',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Technology'
        },
        {
          name => 'secret',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Technology'
        },
        {
          name => 'tech',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Technology'
        },
        {
          name => 'Technology',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Technology'
        },
        {
          name => 'Technology',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Technology'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Technology',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a default technology. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Technology',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'struct_technology',
                  content => 'Technology'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Name of the tech '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'tech'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The enum for the tech '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'secret'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'If the tech is a secret or not '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'tech',
                type => 'const Tech'
              },
              {
                declaration_name => 'secret',
                type => 'bool',
                default_value => 'false'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The name of the technology '
                }
              ]
            },
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'tech',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Tech'
          },
          {
            kind => 'variable',
            name => 'secret',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The type of technology corresponding to its name If the technology is secret from other players and the effects aren\'t appliable '
                }
              ]
            },
            type => 'bool'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit',
      kind => 'class',
      inner => [
      ],
      all_members => [
        {
          name => 'allegiance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'birth_year',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'class_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'combat_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'convoy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'escaped',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'id',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'landing',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'max_combat_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'movement',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'nationality',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'rebase',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'setMovement',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'Unit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'Unit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'unit_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'upgrading',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Unit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              },
              {
                declaration_name => 'nationality',
                type => 'UnitCountry'
              },
              {
                declaration_name => 'unit_type',
                type => 'UnitType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Unit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a custom unit. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nationality'
                        }
                      ],
                      doc => [
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'class_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'unit_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'combat_value'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'movement'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'rebase'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'landing'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nationality',
                type => 'const UnitCountry'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              },
              {
                declaration_name => 'class_type',
                type => 'const UnitClass'
              },
              {
                declaration_name => 'unit_type',
                type => 'const UnitType'
              },
              {
                declaration_name => 'combat_value',
                type => 'const size_t'
              },
              {
                declaration_name => 'movement',
                type => 'const size_t'
              },
              {
                declaration_name => 'rebase',
                type => 'const bool'
              },
              {
                declaration_name => 'landing',
                type => 'const bool',
                default_value => 'false'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setMovement',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Set the movement of the unit. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mov'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new unit of the unit '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mov',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Print out the data of the unit. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'id',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'ID of the unit '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'allegiance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which power the unit belongs to (West, Axis, USSR, Neutral) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'nationality',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which country the unit comes from (West:British, USA, France; Axis: Germany, Italy; USSR: USSR) '
                }
              ]
            },
            type => 'UnitCountry'
          },
          {
            kind => 'variable',
            name => 'class_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which class the unit is in that is mostly just for movement and ReBase '
                }
              ]
            },
            type => 'UnitClass'
          },
          {
            kind => 'variable',
            name => 'unit_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which type of unit that decied attack and movement (Fortress, Infantry, Air...) '
                }
              ]
            },
            type => 'UnitType'
          },
          {
            kind => 'variable',
            name => 'birth_year',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The year that the unit was created in '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'upgrading',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The year after the year which the unit was upgraded in '
                }
              ]
            },
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'combat_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Functions as how many forces are in the one unit and how many it fires in battle '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'max_combat_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Limits the max amount of forces can be in the unit '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'movement',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The max amount of cities it can move in one turn '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'rebase',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If this unit can ReBase (move freely to ground force) '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          },
          {
            kind => 'variable',
            name => 'landing',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The year the unit landed from water this turn (therefore it can\'t attack) '
                }
              ]
            },
            type => 'size_t',
            initializer => '=0'
          },
          {
            kind => 'variable',
            name => 'convoy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the ground unit is a convoy its an infantry in the water and can\'t attack '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          },
          {
            kind => 'variable',
            name => 'escaped',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Used for subs and if they have \'escaped\' and can block trade routes '
                }
              ]
            },
            type => 'bool',
            initializer => '=false'
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  concepts => [
  ],
  modules => [
  ],
  namespaces => [
    {
      name => 'Colors',
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'BLACK',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 0, 0, 255}'
          },
          {
            kind => 'variable',
            name => 'GREEN',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 255, 0, 255}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Graphics',
      classes => [
        {
          name => 'Graphics::Screen'
        }
      ],
      brief => {},
      detailed => {}
    }
  ],
  files => [
    {
      name => 'Graphics.h',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
        {
          name => 'main.cpp',
          ref => 'main_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Includes.h',
      includes => [
        {
          name => 'iostream'
        },
        {
          name => 'fstream'
        },
        {
          name => 'vector'
        },
        {
          name => 'unordered_map'
        },
        {
          name => 'cstdio'
        },
        {
          name => 'sstream'
        },
        {
          name => 'queue'
        },
        {
          name => 'stack'
        },
        {
          name => 'cmath'
        },
        {
          name => 'random'
        },
        {
          name => 'algorithm'
        },
        {
          name => '../include/SDL2/SDL.h'
        },
        {
          name => '../include/SDL2_image/SDL_image.h'
        },
        {
          name => '../include/SDL2/SDL_gamecontroller.h'
        }
      ],
      included_by => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'END_YEAR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '1945;'
          },
          {
            kind => 'define',
            name => 'START_YEAR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '1936;'
          },
          {
            kind => 'define',
            name => 'INFI',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => 'SIZE_MAX;'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => 'CityType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'WEST',
                brief => {},
                detailed => {}
              },
              {
                name => 'AXIS',
                brief => {},
                detailed => {}
              },
              {
                name => 'USSR',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL_AT_WAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'WATER',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'PowerType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'GREAT',
                brief => {},
                detailed => {}
              },
              {
                name => 'MAJOR',
                brief => {},
                detailed => {}
              },
              {
                name => 'COLONY',
                brief => {},
                detailed => {}
              },
              {
                name => 'MINOR',
                brief => {},
                detailed => {}
              },
              {
                name => 'NONE',
                brief => {},
                detailed => {}
              },
              {
                name => 'SEA',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'PopulationType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'EMPTY',
                brief => {},
                detailed => {}
              },
              {
                name => 'TOWN',
                brief => {},
                detailed => {}
              },
              {
                name => 'CITY',
                brief => {},
                detailed => {}
              },
              {
                name => 'CAPITAL_CITY',
                brief => {},
                detailed => {}
              },
              {
                name => 'SUB_CAPITAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'MAIN_CAPITAL',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'ResourceType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NORMAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'TRANS_ATLANTIC',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'BorderType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NA',
                brief => {},
                detailed => {}
              },
              {
                name => 'OCEAN',
                brief => {},
                detailed => {}
              },
              {
                name => 'DEEP_OCEAN',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST',
                brief => {},
                detailed => {}
              },
              {
                name => 'WATER_STRAIT',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST_MOUNTAIN',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST_FOREST',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST_RIVER',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST_PLAINS',
                brief => {},
                detailed => {}
              },
              {
                name => 'MOUNTAIN',
                brief => {},
                detailed => {}
              },
              {
                name => 'FOREST',
                brief => {},
                detailed => {}
              },
              {
                name => 'RIVER',
                brief => {},
                detailed => {}
              },
              {
                name => 'PLAINS',
                brief => {},
                detailed => {}
              },
              {
                name => 'LAND_STRAIT',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitClass',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'CLASS_A',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_N',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_G',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_S',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'FORTRESS',
                brief => {},
                detailed => {}
              },
              {
                name => 'AIR',
                brief => {},
                detailed => {}
              },
              {
                name => 'CARRIER',
                brief => {},
                detailed => {}
              },
              {
                name => 'SUB',
                brief => {},
                detailed => {}
              },
              {
                name => 'FLEET',
                brief => {},
                detailed => {}
              },
              {
                name => 'TANK',
                brief => {},
                detailed => {}
              },
              {
                name => 'INFANTRY',
                brief => {},
                detailed => {}
              },
              {
                name => 'CONVOY',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitCountry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'BRITIAN_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'FRANCE_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'USA_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'GERMANY_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'ITALY_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'USSR_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL_U',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'Season',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NEW_YEAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'SUMMER',
                brief => {},
                detailed => {}
              },
              {
                name => 'FALL',
                brief => {},
                detailed => {}
              },
              {
                name => 'SPRING',
                brief => {},
                detailed => {}
              },
              {
                name => 'WINTER',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'DowState',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'PEACE',
                brief => {},
                detailed => {}
              },
              {
                name => 'DECLARED',
                brief => {},
                detailed => {}
              },
              {
                name => 'VICTIM',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'InvestType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'TECHNOLOGY',
                brief => {},
                detailed => {}
              },
              {
                name => 'INTELLIGENCE',
                brief => {},
                detailed => {}
              },
              {
                name => 'YEAR',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'ActionType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'DIPLOMACY',
                brief => {},
                detailed => {}
              },
              {
                name => 'WILD',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'InfluenceType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'UNALIGNED',
                brief => {},
                detailed => {}
              },
              {
                name => 'ASSOCIATES',
                brief => {},
                detailed => {}
              },
              {
                name => 'PROTECTORATES',
                brief => {},
                detailed => {}
              },
              {
                name => 'SATELLITES',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'BoardState',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'HOME_BOARD',
                brief => {},
                detailed => {}
              },
              {
                name => 'PRODUCTION_BOARD',
                brief => {},
                detailed => {}
              },
              {
                name => 'GOVERNMENT_BOARD',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'ProductionAction',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'BUY_AC',
                brief => {},
                detailed => {}
              },
              {
                name => 'BUY_IC',
                brief => {},
                detailed => {}
              },
              {
                name => 'UNIT_UP',
                brief => {},
                detailed => {}
              },
              {
                name => 'CADRE',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'ProductionError',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'ABLE',
                initializer => '= 0',
                brief => {},
                detailed => {}
              },
              {
                name => 'OUTSIDE_HOME',
                initializer => '= 1',
                brief => {},
                detailed => {}
              },
              {
                name => 'PRE_FORTRESS',
                brief => {},
                detailed => {}
              },
              {
                name => 'UNIT_MAXED',
                brief => {},
                detailed => {}
              },
              {
                name => 'ENEMY_FORTRESS',
                brief => {},
                detailed => {}
              },
              {
                name => 'AT_SEA',
                initializer => '= 10',
                brief => {},
                detailed => {}
              },
              {
                name => 'ENGAGED',
                brief => {},
                detailed => {}
              },
              {
                name => 'UNSUPPLIED',
                brief => {},
                detailed => {}
              },
              {
                name => 'MAX_CV',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'Tech',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'LSTs',
                brief => {},
                detailed => {}
              },
              {
                name => 'MOTORIZED_INFANTRY',
                brief => {},
                detailed => {}
              },
              {
                name => 'NAVAL_RADAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'ROCKET_ARTILLERY',
                brief => {},
                detailed => {}
              },
              {
                name => 'HEAVY_TANKS',
                brief => {},
                detailed => {}
              },
              {
                name => 'HEAVY_BOMBERS',
                brief => {},
                detailed => {}
              },
              {
                name => 'PERCISION_BOMBERS',
                brief => {},
                detailed => {}
              },
              {
                name => 'JETs',
                brief => {},
                detailed => {}
              },
              {
                name => 'SONAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'AIRDEFENCE_RADAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'COUP',
                brief => {},
                detailed => {}
              },
              {
                name => 'CODE_BREAKER',
                brief => {},
                detailed => {}
              },
              {
                name => 'AGENT',
                brief => {},
                detailed => {}
              },
              {
                name => 'MOLE',
                brief => {},
                detailed => {}
              },
              {
                name => 'SABOTAGE',
                brief => {},
                detailed => {}
              },
              {
                name => 'SPY_RING',
                brief => {},
                detailed => {}
              },
              {
                name => 'DOUBLE_AGENT',
                brief => {},
                detailed => {}
              },
              {
                name => 'ATOMIC_ONE',
                brief => {},
                detailed => {}
              },
              {
                name => 'ATOMIC_TWO',
                brief => {},
                detailed => {}
              },
              {
                name => 'ATOMIC_THREE',
                brief => {},
                detailed => {}
              },
              {
                name => 'ATOMIC_FOUR',
                brief => {},
                detailed => {}
              },
              {
                name => 'Y_1938',
                brief => {},
                detailed => {}
              },
              {
                name => 'Y_1940',
                brief => {},
                detailed => {}
              },
              {
                name => 'Y_1942',
                brief => {},
                detailed => {}
              },
              {
                name => 'Y_1944',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'JOYSTICK_DEADZONE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            initializer => '= 16000'
          },
          {
            kind => 'variable',
            name => 'NATIONALITY_STRING',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const string',
            arguments => '[7]',
            initializer => '= {"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"}'
          },
          {
            kind => 'variable',
            name => 'FIREPOWER_TABLE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[8][4]',
            initializer => '= { 
    {2, 3, 4, 3}, 
    {3, 1, 1, 1}, 
    {2, 2, 1, 2}, 
    {2, 2, 1, 2}, 
    {1, 3, 1, 2}, 
    {0, 0, 2, 0}, 
    {1, 1, 3, 0}, 
    {0, 0, 0, 0}  
}'
          },
          {
            kind => 'variable',
            name => 'MAX_CV_TABLE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[8][7]',
            initializer => '= { 
    {4, 3, 4, 4, 3, 3, 3}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {0, 0, 0, 0, 0, 3, 0}  
}'
          },
          {
            kind => 'variable',
            name => 'UNIT_COUNTS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[7][7]',
            initializer => '= {
    
    {6, 3, 2, 8,  2, 6,  8}, 
    {4, 3, 4, 8,  3, 6,  0}, 
    {2, 1, 1, 2,  1, 2,  0}, 
    {3, 1, 1, 8,  2, 2,  0}, 
    {6, 4, 4, 6,  4, 4,  0}, 
    {3, 2, 4, 8,  2, 8,  0}, 
    {6, 6, 4, 16, 6, 16, 0} 
}'
          },
          {
            kind => 'variable',
            name => 'BORDER_COLOR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[14][3]',
            initializer => '{ 
    {0,0,0},            
    {0, 59, 255},        
    {4, 35, 137},        
    {4, 136, 137},         
    {245, 255, 78},     
    {51, 189, 190},        
    {60, 165, 98},    
    {92, 193, 176},    
    {82, 90, 111},    
    {79, 79, 79},    
    {37, 224, 75},    
    {54, 236, 237},    
    {155, 255, 174},    
    {196, 237, 49}    
}'
          },
          {
            kind => 'variable',
            name => 'SEVEN_SEGMENT_DISPLAY',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const bool',
            arguments => '[10][7]',
            initializer => '= { 
    { 1,1,1,1,1,1,0 }, 
    { 0,1,1,0,0,0,0 }, 
    { 1,1,0,1,1,0,1 }, 
    { 1,1,1,1,0,0,1 }, 
    { 0,1,1,0,0,1,1 }, 
    { 1,0,1,1,0,1,1 }, 
    { 1,0,1,1,1,1,1 }, 
    { 1,1,1,0,0,0,0 }, 
    { 1,1,1,1,1,1,1 }, 
    { 1,1,1,0,0,1,1 }  
}'
          },
          {
            kind => 'variable',
            name => 'ZOOM_DIMENSIONS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[3][2]',
            initializer => '= {
    {20, 20}, 
    {40, 40}, 
    {64, 64}  
}'
          },
          {
            kind => 'variable',
            name => 'UNIT_SPRITE_OFFSET',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[7]',
            initializer => '{ 
    0, 5, 9, 14, 19, 23, 27
}'
          },
          {
            kind => 'variable',
            name => 'BLACK',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 0, 0, 255}'
          },
          {
            kind => 'variable',
            name => 'GREEN',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 255, 0, 255}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'main.cpp',
      includes => [
        {
          name => 'Graphics.h',
          ref => '_graphics_8h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'SDL_MAIN_HANDELED',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'argc',
                type => 'int'
              },
              {
                declaration_name => 'argv',
                type => 'char *',
                array => '[]'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Map.cpp',
      includes => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Map.h',
      includes => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      included_by => [
        {
          name => 'Map.cpp',
          ref => '_map_8cpp'
        },
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Player.cpp',
      includes => [
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Player.h',
      includes => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        }
      ],
      included_by => [
        {
          name => 'Player.cpp',
          ref => '_player_8cpp'
        },
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Runner.cpp',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Runner.h',
      includes => [
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      included_by => [
        {
          name => 'Graphics.h',
          ref => '_graphics_8h'
        },
        {
          name => 'Runner.cpp',
          ref => '_runner_8cpp'
        },
        {
          name => 'Sequence.cpp',
          ref => '_sequence_8cpp'
        },
        {
          name => 'UserInput.cpp',
          ref => '_user_input_8cpp'
        }
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'event_filter',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Since controllers can have stick drift, it will flood the SDL_PollEvent Queue with joystick moves and delay user inputs. The filter will only allow significant movements to be placed in queue. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'userdata'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => '??? '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The event picked up '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'int 1: if the event should be recorded 0: if to be ignored '
                    }
                  ]
                }
              ]
            },
            type => 'static int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'userdata',
                type => 'void *'
              },
              {
                declaration_name => 'event',
                type => 'SDL_Event *'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'SDL_image.h',
      includes => [
        {
          name => '../lib/SDL.h'
        },
        {
          name => '../lib/SDL_version.h'
        },
        {
          name => '../lib/begin_code.h'
        },
        {
          name => '../lib/close_code.h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'SDL_IMAGE_MAJOR_VERSION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Printable format: "%d.%d.%d", MAJOR, MINOR, PATCHLEVEL '
                }
              ]
            },
            initializer => '2'
          },
          {
            kind => 'define',
            name => 'SDL_IMAGE_MINOR_VERSION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '8'
          },
          {
            kind => 'define',
            name => 'SDL_IMAGE_PATCHLEVEL',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '2'
          },
          {
            kind => 'define',
            name => 'SDL_IMAGE_VERSION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This macro can be used to fill a version structure with the compile-time version of the SDL_image library. '
                }
              ]
            },
            parameters => [
              {
                name => 'X'
              }
            ],
            initializer => '{                                                   \\
    (X)->major = SDL_IMAGE_MAJOR_VERSION;           \\
    (X)->minor = SDL_IMAGE_MINOR_VERSION;           \\
    (X)->patch = SDL_IMAGE_PATCHLEVEL;              \\
}'
          },
          {
            kind => 'define',
            name => 'SDL_IMAGE_COMPILEDVERSION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the version number macro for the current SDL_image version.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'In versions higher than 2.9.0, the minor version overflows into the thousands digit: for example, 2.23.0 is encoded as 4300. This macro will not be available in SDL 3.x or SDL_image 3.x.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Deprecated, use SDL_IMAGE_VERSION_ATLEAST or SDL_IMAGE_VERSION instead. '
                }
              ]
            },
            initializer => '    SDL_VERSIONNUM(SDL_IMAGE_MAJOR_VERSION, SDL_IMAGE_MINOR_VERSION, SDL_IMAGE_PATCHLEVEL)'
          },
          {
            kind => 'define',
            name => 'SDL_IMAGE_VERSION_ATLEAST',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This macro will evaluate to true if compiled with SDL_image at least X.Y.Z. '
                }
              ]
            },
            parameters => [
              {
                name => 'X'
              },
              {
                name => 'Y'
              },
              {
                name => 'Z'
              }
            ],
            initializer => '    ((SDL_IMAGE_MAJOR_VERSION >= X) && \\
     (SDL_IMAGE_MAJOR_VERSION > X || SDL_IMAGE_MINOR_VERSION >= Y) && \\
     (SDL_IMAGE_MAJOR_VERSION > X || SDL_IMAGE_MINOR_VERSION > Y || SDL_IMAGE_PATCHLEVEL >= Z))'
          },
          {
            kind => 'define',
            name => 'IMG_SetError',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Report SDL_image errors'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa26bff3cc4fbcfd9dcc1756d1a398ba1',
                      content => 'IMG_GetError'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            initializer => 'SDL_SetError'
          },
          {
            kind => 'define',
            name => 'IMG_GetError',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get last SDL_image error'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4f62490add1442e80bffdc07c959f10f',
                      content => 'IMG_SetError'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            initializer => 'SDL_GetError'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => 'IMG_InitFlags',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initialization flags '
                }
              ]
            },
            values => [
              {
                name => 'IMG_INIT_JPG',
                initializer => '= 0x00000001',
                brief => {},
                detailed => {}
              },
              {
                name => 'IMG_INIT_PNG',
                initializer => '= 0x00000002',
                brief => {},
                detailed => {}
              },
              {
                name => 'IMG_INIT_TIF',
                initializer => '= 0x00000004',
                brief => {},
                detailed => {}
              },
              {
                name => 'IMG_INIT_WEBP',
                initializer => '= 0x00000008',
                brief => {},
                detailed => {}
              },
              {
                name => 'IMG_INIT_JXL',
                initializer => '= 0x00000010',
                brief => {},
                detailed => {}
              },
              {
                name => 'IMG_INIT_AVIF',
                initializer => '= 0x00000020',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'IMG_Linked_Version',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function gets the version of the dynamically linked SDL_image library.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'it should NOT be used to fill a version structure, instead you should use the '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a80cd9402fef02541862a12cea00ed1cc',
                  content => 'SDL_IMAGE_VERSION()'
                },
                {
                  type => 'text',
                  content => ' macro.'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL_image version '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC const SDL_version *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'void'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_Init',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initialize SDL_image.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function loads dynamic libraries that SDL_image needs, and prepares them for use. This must be the first function you call in SDL_image, and if it fails you should not continue with the library.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Flags should be one or more flags from IMG_InitFlags OR\'d together. It returns the flags successfully initialized, or 0 on failure.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Currently, these flags are:'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'list',
                  style => 'itemized',
                  content => [
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_JPG'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ],
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_PNG'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ],
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_TIF'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ],
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_WEBP'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ],
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_JXL'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ],
                    [
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'yes'
                      },
                      {
                        type => 'text',
                        content => 'IMG_INIT_AVIF'
                      },
                      {
                        type => 'style',
                        style => 'code',
                        enable => 'no'
                      }
                    ]
                  ]
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'More flags may be added in a future SDL_image release.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function may need to load external shared libraries to support various codecs, which means this function can fail to initialize that support on an otherwise-reasonable system if the library isn\'t available; this is not just a question of exceptional circumstances like running out of memory at startup!'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Note that you may call this function more than once to initialize with additional flags. The return value will reflect both new flags that successfully initialized, and also include flags that had previously been initialized as well.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'As this will return previously-initialized flags, it\'s legal to call this with zero (no flags set). This is a safe no-op that can be used to query the current initialization state without changing it at all.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Since this returns previously-initialized flags as well as new ones, and you can call this with zero, you should not check for a zero return value to determine an error condition. Instead, you should check to make sure all the flags you require are set in the return value. If you have a game with data in a specific format, this might be a fatal error. If you\'re a generic image displaying app, perhaps you are fine with only having JPG and PNG support and can live without WEBP, even if you request support for everything.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Unlike other SDL satellite libraries, calls to IMG_Init do not stack; a single call to '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a8e5db0b68bf88958f87b189a8960e39c',
                  content => 'IMG_Quit()'
                },
                {
                  type => 'text',
                  content => ' will deinitialize everything and does not have to be paired with a matching IMG_Init call. For that reason, it\'s considered best practices to have a single IMG_Init and IMG_Quit call in your program. While this isn\'t required, be aware of the risks of deviating from that behavior.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'After initializing SDL_image, the app may begin to load images into SDL_Surfaces or SDL_Textures.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'flags'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'initialization flags, OR\'d together. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'all currently initialized flags.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8e5db0b68bf88958f87b189a8960e39c',
                      content => 'IMG_Quit'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'flags',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_Quit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Deinitialize SDL_image.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This should be the last function you call in SDL_image, after freeing all other resources. This will unload any shared libraries it is using for various codecs.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'After this call, a call to IMG_Init(0) will return 0 (no codecs loaded).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You can safely call '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1aff993a37c1f1859b38e2b4e8ff808a6b',
                  content => 'IMG_Init()'
                },
                {
                  type => 'text',
                  content => ' to reload various codec support after this call.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Unlike other SDL satellite libraries, calls to IMG_Init do not stack; a single call to '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a8e5db0b68bf88958f87b189a8960e39c',
                  content => 'IMG_Quit()'
                },
                {
                  type => 'text',
                  content => ' will deinitialize everything and does not have to be paired with a matching IMG_Init call. For that reason, it\'s considered best practices to have a single IMG_Init and IMG_Quit call in your program. While this isn\'t required, be aware of the risks of deviating from that behavior.'
                },
                {
                  type => 'parbreak'
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aff993a37c1f1859b38e2b4e8ff808a6b',
                      content => 'IMG_Init'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC void SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'void'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadTyped_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an image from an SDL data source into a software surface.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An SDL_Surface is a buffer of pixels in memory accessible by the CPU. Use this if you plan to hand the data to something else or manipulate it further in code.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There are no guarantees about what format the new SDL_Surface data will be; in many cases, SDL_image will attempt to supply a surface that exactly matches the provided image, but in others it might have to convert (either because the image is in a format that SDL doesn\'t directly support or because it\'s compressed data that could reasonably uncompress to various formats and SDL_image had to pick one). You can inspect an SDL_Surface for its specifics, and use SDL_ConvertSurface to then migrate to any supported format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the image format supports a transparent pixel, SDL will set the colorkey for the surface. You can enable RLE acceleration on the surface afterwards by calling: SDL_SetColorKey(image, SDL_RLEACCEL, image->format->colorkey);'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'freesrc'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is non-zero, the RWops will be closed before returning, whether this function succeeds or not. SDL_image reads everything it needs from the RWops during this call in any case.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Even though this function accepts a file type, SDL_image may still try other decoders that are capable of detecting file type from the contents of the image data, but may rely on the caller-provided type string for formats that it cannot autodetect. If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'type'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is NULL, SDL_image will rely solely on its ability to guess the format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is a separate function to read files from disk without having to deal with SDL_RWops: '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'IMG_Load("filename.jpg")'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' will call this function and manage those details for you, determining the file type from the filename\'s extension.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is also '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1ac045c6da943f8fd9284a4abb255dda24',
                  content => 'IMG_Load_RW()'
                },
                {
                  type => 'text',
                  content => ', which is equivalent to this function except that it will rely on SDL_image to determine what type of data it is loading, much like passing a NULL for type.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you are using SDL\'s 2D rendering API, there is an equivalent call to load images directly into an SDL_Texture for use by the GPU without using a software surface: call IMG_LoadTextureTyped_RW() instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'freesrc'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'non-zero to close/free the SDL_RWops before returning, zero to leave it open. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'a filename extension that represent this data ("BMP", "GIF", "PNG", etc). '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa21efc052860dbaa49c905fa62d366a4',
                      content => 'IMG_Load'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac045c6da943f8fd9284a4abb255dda24',
                      content => 'IMG_Load_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'SDL_FreeSurface '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freesrc',
                type => 'int'
              },
              {
                declaration_name => 'type',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_Load',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an image from a filesystem path into a software surface.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An SDL_Surface is a buffer of pixels in memory accessible by the CPU. Use this if you plan to hand the data to something else or manipulate it further in code.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There are no guarantees about what format the new SDL_Surface data will be; in many cases, SDL_image will attempt to supply a surface that exactly matches the provided image, but in others it might have to convert (either because the image is in a format that SDL doesn\'t directly support or because it\'s compressed data that could reasonably uncompress to various formats and SDL_image had to pick one). You can inspect an SDL_Surface for its specifics, and use SDL_ConvertSurface to then migrate to any supported format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the image format supports a transparent pixel, SDL will set the colorkey for the surface. You can enable RLE acceleration on the surface afterwards by calling: SDL_SetColorKey(image, SDL_RLEACCEL, image->format->colorkey);'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is a separate function to read files from an SDL_RWops, if you need an i/o abstraction to provide data from anywhere instead of a simple filesystem read; that function is '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1ac045c6da943f8fd9284a4abb255dda24',
                  content => 'IMG_Load_RW()'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you are using SDL\'s 2D rendering API, there is an equivalent call to load images directly into an SDL_Texture for use by the GPU without using a software surface: call IMG_LoadTexture() instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a path on the filesystem to load an image from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1acd35c69d298b9954418420d5e94f28f3',
                      content => 'IMG_LoadTyped_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac045c6da943f8fd9284a4abb255dda24',
                      content => 'IMG_Load_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'SDL_FreeSurface '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_Load_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an image from an SDL data source into a software surface.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An SDL_Surface is a buffer of pixels in memory accessible by the CPU. Use this if you plan to hand the data to something else or manipulate it further in code.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There are no guarantees about what format the new SDL_Surface data will be; in many cases, SDL_image will attempt to supply a surface that exactly matches the provided image, but in others it might have to convert (either because the image is in a format that SDL doesn\'t directly support or because it\'s compressed data that could reasonably uncompress to various formats and SDL_image had to pick one). You can inspect an SDL_Surface for its specifics, and use SDL_ConvertSurface to then migrate to any supported format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the image format supports a transparent pixel, SDL will set the colorkey for the surface. You can enable RLE acceleration on the surface afterwards by calling: SDL_SetColorKey(image, SDL_RLEACCEL, image->format->colorkey);'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'freesrc'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is non-zero, the RWops will be closed before returning, whether this function succeeds or not. SDL_image reads everything it needs from the RWops during this call in any case.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is a separate function to read files from disk without having to deal with SDL_RWops: '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'IMG_Load("filename.jpg")'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' will call this function and manage those details for you, determining the file type from the filename\'s extension.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is also '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1acd35c69d298b9954418420d5e94f28f3',
                  content => 'IMG_LoadTyped_RW()'
                },
                {
                  type => 'text',
                  content => ', which is equivalent to this function except a file extension (like "BMP", "JPG", etc) can be specified, in case SDL_image cannot autodetect the file format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you are using SDL\'s 2D rendering API, there is an equivalent call to load images directly into an SDL_Texture for use by the GPU without using a software surface: call IMG_LoadTexture_RW() instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'freesrc'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'non-zero to close/free the SDL_RWops before returning, zero to leave it open. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa21efc052860dbaa49c905fa62d366a4',
                      content => 'IMG_Load'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1acd35c69d298b9954418420d5e94f28f3',
                      content => 'IMG_LoadTyped_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'SDL_FreeSurface '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freesrc',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isAVIF',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect AVIF image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is AVIF data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isICO',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect ICO image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is ICO data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isCUR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect CUR image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is CUR data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isBMP',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect BMP image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is BMP data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isGIF',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect GIF image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is GIF data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isJPG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect JPG image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is JPG data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isJXL',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect JXL image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is JXL data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isLBM',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect LBM image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is LBM data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isPCX',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect PCX image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is PCX data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isPNG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect PNG image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is PNG data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isPNM',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect PNM image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is PNM data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isSVG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect SVG image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is SVG data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.2.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isQOI',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect QOI image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is QOI data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isTIF',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect TIFF image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is TIFF data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isXCF',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect XCF image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is XCF data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isXPM',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect XPM image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is XPM data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isXV',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect XV image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is XV data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7025426b75f60226f8b28c87aa876c38',
                      content => 'IMG_isWEBP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_isWEBP',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Detect WEBP image data on a readable/seekable SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function attempts to determine if a file is a given filetype, reading the least amount possible from the SDL_RWops (usually a few bytes).'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'There is no distinction made between "not the filetype in question" and basic i/o errors.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function will always attempt to seek the RWops back to where it started when this function was called, but it will not report any errors in doing so, but assuming seeking works, this means you can immediately use this with a different IMG_isTYPE function, or load the image without further seeking.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'You do not need to call this function to load data; SDL_image can work to determine file type in many cases in its standard load functions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a seekable/readable SDL_RWops to provide image data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'non-zero if this is WEBP data, zero otherwise.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2e55a6a9e001413a077714fdbfc9f592',
                      content => 'IMG_isAVIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a1156b631a02d4e0d7bbe1613030732fe',
                      content => 'IMG_isICO'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a8133fd3d50ad02b997018db5808022cc',
                      content => 'IMG_isCUR'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a16f1295242a93f8874571822d0a4266f',
                      content => 'IMG_isBMP'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a44c30b8372d658281397a2075cbd4465',
                      content => 'IMG_isGIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82a9955fa3426a32cdefac82252c7f46',
                      content => 'IMG_isJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40f8d095da3a646cfacc0632d479bdcc',
                      content => 'IMG_isJXL'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac0cb4f0ee51f1bdf4f35921955781c4f',
                      content => 'IMG_isLBM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9a7865013705a9f44cc2e2a242326426',
                      content => 'IMG_isPCX'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1add480a3da37b41b1a2faae64847edddf',
                      content => 'IMG_isPNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a42f66fa7ec38e5245d759b7d27ab6632',
                      content => 'IMG_isPNM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f71787cd6a8ab6aa317aff9377e4ea',
                      content => 'IMG_isSVG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af5a0b8c880400e9e2a6a3b49dcbab6bf',
                      content => 'IMG_isQOI'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9199b0f040ec188a36431271fc7d741e',
                      content => 'IMG_isTIF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae6c6a6b54a08b08213d2876a6e043035',
                      content => 'IMG_isXCF'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a923cd9fc663faa0f5381da2ab535be76',
                      content => 'IMG_isXPM'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae388104ac6f46574382edffdb4f09d00',
                      content => 'IMG_isXV'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadAVIF_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a AVIF image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a AVIF image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadICO_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a ICO image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a ICO image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadCUR_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a CUR image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a CUR image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadBMP_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a BMP image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a BMP image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadGIF_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a GIF image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a GIF image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadJPG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a JPG image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a JPG image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadJXL_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a JXL image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a JXL image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadLBM_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a LBM image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a LBM image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadPCX_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a PCX image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a PCX image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadPNG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a PNG image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a PNG image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadPNM_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a PNM image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a PNM image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadSVG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a SVG image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a SVG image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.2.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadQOI_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a QOI image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a QOI image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadTGA_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a TGA image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a TGA image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadTIF_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a TIFF image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a TIFF image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadXCF_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a XCF image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a XCF image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadXPM_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a XPM image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a XPM image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadXV_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a XV image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a XV image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab8bd54f73497cd6024170e10a155d2bf',
                      content => 'IMG_LoadWEBP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadWEBP_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a WEBP image directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a WEBP image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load image data from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL surface, or NULL on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac5d5c73e3ce6e5de382b37e12792cd56',
                      content => 'IMG_LoadAVIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7d98fe773172ac0beeb38c9f467142fd',
                      content => 'IMG_LoadICO_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a51309e70ec65f63419bbf1a9c535e357',
                      content => 'IMG_LoadCUR_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a82331e860ed3ee86c4456251e73c5a89',
                      content => 'IMG_LoadBMP_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1afd5f3cd0d53a3712bd376c07158abd1c',
                      content => 'IMG_LoadGIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a47e4f89e574ec9ecc1a7e1e3d88785a3',
                      content => 'IMG_LoadJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a40c866590e972fc023b0c1371eccdedd',
                      content => 'IMG_LoadJXL_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a11e9a938c23c903b85ab604be25a69ad',
                      content => 'IMG_LoadLBM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ac3f2f97096945107027bd2f22944785a',
                      content => 'IMG_LoadPCX_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a2f12a4946c45df84cadf12ac4378ec4d',
                      content => 'IMG_LoadPNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ad1243468c641b99350ef52e41b3524e6',
                      content => 'IMG_LoadPNM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aca4156ffc85ec8f43205515c650ca09e',
                      content => 'IMG_LoadSVG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a06f405b12b31d793c961c4c1404dc519',
                      content => 'IMG_LoadQOI_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a46316cf78da8c10a132d7d28981187be',
                      content => 'IMG_LoadTGA_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9df9afa54e440f8b2863197df10fd1ba',
                      content => 'IMG_LoadTIF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a458c50ce937a1efa1f8cb1b60190ddd8',
                      content => 'IMG_LoadXCF_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ab4a3231009b398e784be6c639a6f513b',
                      content => 'IMG_LoadXPM_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1af1aebb147f6a4e6c386d8b954739bcc1',
                      content => 'IMG_LoadXV_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadSizedSVG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an SVG image, scaled to a specific size.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Since SVG files are resolution-independent, you specify the size you would like the output image to be and it will be generated at those dimensions.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Either width or height may be 0 and the image will be auto-sized to preserve aspect ratio.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops to load SVG data from. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'width'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'desired width of the generated surface, in pixels. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'height'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'desired height of the generated surface, in pixels. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0. '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'width',
                type => 'int'
              },
              {
                declaration_name => 'height',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_ReadXPMFromArray',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an XPM image from a memory array.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The returned surface will be an 8bpp indexed surface, if possible, otherwise it will be 32bpp. If you always want 32-bit data, use '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1aabcc9ea7e45761faecd068ceb0b2a6b9',
                  content => 'IMG_ReadXPMFromArrayToRGB888()'
                },
                {
                  type => 'text',
                  content => ' instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'xpm'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a null-terminated array of strings that comprise XPM data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aabcc9ea7e45761faecd068ceb0b2a6b9',
                      content => 'IMG_ReadXPMFromArrayToRGB888'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'xpm',
                type => 'char **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_ReadXPMFromArrayToRGB888',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an XPM image from a memory array.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The returned surface will always be a 32-bit RGB surface. If you want 8-bit indexed colors (and the XPM data allows it), use '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a4cd5d72066ee02df15b528f2c54bb2d9',
                  content => 'IMG_ReadXPMFromArray()'
                },
                {
                  type => 'text',
                  content => ' instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned surface, the app should dispose of it with a call to SDL_FreeSurface().'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'xpm'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'a null-terminated array of strings that comprise XPM data. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new SDL surface, or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4cd5d72066ee02df15b528f2c54bb2d9',
                      content => 'IMG_ReadXPMFromArray'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC SDL_Surface *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'xpm',
                type => 'char **'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_SavePNG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Save an SDL_Surface into a PNG image file.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the file already exists, it will be overwritten.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'surface'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'the SDL surface to save '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'path on the filesystem to write new file to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '0 if successful, -1 on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7cf088e13df693a3dcff2d1d563cf4c0',
                      content => 'IMG_SavePNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa8ef847f8c7c12f0e445715da3eb7b04',
                      content => 'IMG_SaveJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae319e6660d7d42fa1885ab3ea38c72c7',
                      content => 'IMG_SaveJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'surface',
                type => 'SDL_Surface *'
              },
              {
                declaration_name => 'file',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_SavePNG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Save an SDL_Surface into PNG image data, via an SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you just want to save to a filename, you can use '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a4570b11898b9350e5478d3b4394c5d70',
                  content => 'IMG_SavePNG()'
                },
                {
                  type => 'text',
                  content => ' instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'surface'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'the SDL surface to save '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'dst'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'the SDL_RWops to save the image data to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '0 if successful, -1 on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4570b11898b9350e5478d3b4394c5d70',
                      content => 'IMG_SavePNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa8ef847f8c7c12f0e445715da3eb7b04',
                      content => 'IMG_SaveJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae319e6660d7d42fa1885ab3ea38c72c7',
                      content => 'IMG_SaveJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'surface',
                type => 'SDL_Surface *'
              },
              {
                declaration_name => 'dst',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freedst',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_SaveJPG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Save an SDL_Surface into a JPEG image file.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the file already exists, it will be overwritten.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'surface'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'the SDL surface to save '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'path on the filesystem to write new file to. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'quality'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => '[0; 33] is Lowest quality, [34; 66] is Middle quality, [67; 100] is Highest quality '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '0 if successful, -1 on error'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.2.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1ae319e6660d7d42fa1885ab3ea38c72c7',
                      content => 'IMG_SaveJPG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4570b11898b9350e5478d3b4394c5d70',
                      content => 'IMG_SavePNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7cf088e13df693a3dcff2d1d563cf4c0',
                      content => 'IMG_SavePNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'surface',
                type => 'SDL_Surface *'
              },
              {
                declaration_name => 'file',
                type => 'const char *'
              },
              {
                declaration_name => 'quality',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_SaveJPG_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Save an SDL_Surface into JPEG image data, via an SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you just want to save to a filename, you can use '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1aa8ef847f8c7c12f0e445715da3eb7b04',
                  content => 'IMG_SaveJPG()'
                },
                {
                  type => 'text',
                  content => ' instead.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'surface'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'the SDL surface to save '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'dst'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'the SDL_RWops to save the image data to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '0 if successful, -1 on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.0.2.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1aa8ef847f8c7c12f0e445715da3eb7b04',
                      content => 'IMG_SaveJPG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4570b11898b9350e5478d3b4394c5d70',
                      content => 'IMG_SavePNG'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a7cf088e13df693a3dcff2d1d563cf4c0',
                      content => 'IMG_SavePNG_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC int SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'surface',
                type => 'SDL_Surface *'
              },
              {
                declaration_name => 'dst',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freedst',
                type => 'int'
              },
              {
                declaration_name => 'quality',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadAnimation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an animation from a file.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned animation, the app should dispose of it with a call to '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                  content => 'IMG_FreeAnimation()'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'path on the filesystem containing an animated image. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new '
                    },
                    {
                      type => 'url',
                      link => 'struct_i_m_g___animation',
                      content => 'IMG_Animation'
                    },
                    {
                      type => 'text',
                      content => ', or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                      content => 'IMG_FreeAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC IMG_Animation *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadAnimation_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an animation from an SDL_RWops.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'freesrc'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is non-zero, the RWops will be closed before returning, whether this function succeeds or not. SDL_image reads everything it needs from the RWops during this call in any case.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned animation, the app should dispose of it with a call to '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                  content => 'IMG_FreeAnimation()'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'freesrc'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'non-zero to close/free the SDL_RWops before returning, zero to leave it open. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new '
                    },
                    {
                      type => 'url',
                      link => 'struct_i_m_g___animation',
                      content => 'IMG_Animation'
                    },
                    {
                      type => 'text',
                      content => ', or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                      content => 'IMG_FreeAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC IMG_Animation *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freesrc',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadAnimationTyped_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load an animation from an SDL datasource'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Even though this function accepts a file type, SDL_image may still try other decoders that are capable of detecting file type from the contents of the image data, but may rely on the caller-provided type string for formats that it cannot autodetect. If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'type'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is NULL, SDL_image will rely solely on its ability to guess the format.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'freesrc'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' is non-zero, the RWops will be closed before returning, whether this function succeeds or not. SDL_image reads everything it needs from the RWops during this call in any case.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When done with the returned animation, the app should dispose of it with a call to '
                },
                {
                  type => 'url',
                  link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                  content => 'IMG_FreeAnimation()'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'freesrc'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'non-zero to close/free the SDL_RWops before returning, zero to leave it open. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'a filename extension that represent this data ("GIF", etc). '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new '
                    },
                    {
                      type => 'url',
                      link => 'struct_i_m_g___animation',
                      content => 'IMG_Animation'
                    },
                    {
                      type => 'text',
                      content => ', or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1adaa846ce4ec52f796e26e941f08bf0e9',
                      content => 'IMG_LoadAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a3a314d29be235c79c7ada13d63f6e8ed',
                      content => 'IMG_LoadAnimation_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                      content => 'IMG_FreeAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC IMG_Animation *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              },
              {
                declaration_name => 'freesrc',
                type => 'int'
              },
              {
                declaration_name => 'type',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_FreeAnimation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Dispose of an '
                },
                {
                  type => 'url',
                  link => 'struct_i_m_g___animation',
                  content => 'IMG_Animation'
                },
                {
                  type => 'text',
                  content => ' and free its resources.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The provided '
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'anim'
                },
                {
                  type => 'style',
                  style => 'code',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' pointer is not valid once this call returns.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'anim'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'struct_i_m_g___animation',
                          content => 'IMG_Animation'
                        },
                        {
                          type => 'text',
                          content => ' to dispose of.'
                        }
                      ]
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1adaa846ce4ec52f796e26e941f08bf0e9',
                      content => 'IMG_LoadAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a3a314d29be235c79c7ada13d63f6e8ed',
                      content => 'IMG_LoadAnimation_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9f658fc0974f4468067abcb05a76ccce',
                      content => 'IMG_LoadAnimationTyped_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC void SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'anim',
                type => 'IMG_Animation *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadGIFAnimation_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a GIF animation directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a GIF image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new '
                    },
                    {
                      type => 'url',
                      link => 'struct_i_m_g___animation',
                      content => 'IMG_Animation'
                    },
                    {
                      type => 'text',
                      content => ', or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1adaa846ce4ec52f796e26e941f08bf0e9',
                      content => 'IMG_LoadAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a3a314d29be235c79c7ada13d63f6e8ed',
                      content => 'IMG_LoadAnimation_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9f658fc0974f4468067abcb05a76ccce',
                      content => 'IMG_LoadAnimationTyped_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                      content => 'IMG_FreeAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC IMG_Animation *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'IMG_LoadWEBPAnimation_RW',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Load a WEBP animation directly.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If you know you definitely have a WEBP image, you can call this function, which will skip SDL_image\'s file format detection routines. Generally it\'s better to use the abstract interfaces; also, there is only an SDL_RWops interface available here.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'src'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'an SDL_RWops that data will be read from. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'a new '
                    },
                    {
                      type => 'url',
                      link => 'struct_i_m_g___animation',
                      content => 'IMG_Animation'
                    },
                    {
                      type => 'text',
                      content => ', or NULL on error.'
                    }
                  ]
                },
                {
                  since => [
                    {
                      type => 'text',
                      content => 'This function is available since SDL_image 2.6.0.'
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1adaa846ce4ec52f796e26e941f08bf0e9',
                      content => 'IMG_LoadAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a3a314d29be235c79c7ada13d63f6e8ed',
                      content => 'IMG_LoadAnimation_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a9f658fc0974f4468067abcb05a76ccce',
                      content => 'IMG_LoadAnimationTyped_RW'
                    },
                    {
                      type => 'text',
                      content => ' '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'url',
                      link => '_s_d_l__image_8h_1a4492e0c6df917d09f551f0105a3f7b2b',
                      content => 'IMG_FreeAnimation'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                }
              ]
            },
            type => 'DECLSPEC IMG_Animation *SDLCALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'src',
                type => 'SDL_RWops *'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Header file for SDL_image library'
          },
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'A simple library to load images of various formats as SDL surfaces '
          }
        ]
      }
    },
    {
      name => 'Sequence.cpp',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit.cpp',
      includes => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit.h',
      includes => [
        {
          name => 'Includes.h',
          ref => '_includes_8h'
        }
      ],
      included_by => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        },
        {
          name => 'Unit.cpp',
          ref => '_unit_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'UserInput.cpp',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    }
  ],
  groups => [
  ],
  pages => [
  ]
};
1;
